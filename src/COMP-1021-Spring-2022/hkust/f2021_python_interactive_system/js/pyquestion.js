(function(pyQuestion) {
    "use strict";

    // Store the regular expression of the unicode spacing
    const unicodeSpaceRegex = /[\u00A0\u1680\u180e\u2000-\u2009\u200a\u200b\u202f\u205f\u3000]/g;

    // Store the icons used by the question types
    const iconRandomOrder = "&#x2B0D;";
    const iconDecreaseIndentation = "&#x21E4;";
    const iconIncreaseIndentation = "&#x21E5;";
    const iconDelete = "&#x2421;";  // This says DEL
    const iconChange = "&#x270e;";  // This is the pencil icon for edit

    // The messages
    const aboutMessage =
            "This is a COMP1021 Introduction to Computer Science learning aid, " + 
            "by Prof. David Rossiter and Prof. Gibson Lam.\n\n" +
            "Please use a PC or a Mac. It's not designed for mobile things.";
    const resetMessage = "Are you sure you want to reset the question?";

    // The four types of Python question; use powers of 2
    pyQuestion.questionTypeRandomOrder = 1;
    pyQuestion.questionTypeIndentation = 2;
    pyQuestion.questionTypeDeleteLines = 4;
    pyQuestion.questionTypeChangeCode  = 8;
    pyQuestion.questionTypeChangeCodeWebDisplay  = 16; // send student lines of code to server

    // The random behaviour of Python question; use powers of 2
    pyQuestion.questionHasRandomBehaviour = 32;

    // The message content for the question types
    pyQuestion.questionMessage = {};
    pyQuestion.questionMessage[pyQuestion.questionTypeRandomOrder] = 
            "The order of the code has been randomly changed. " + 
            "Click and drag the lines of code so they are in the right order.";
    pyQuestion.questionMessage[pyQuestion.questionTypeIndentation] =
            "The indentation of some lines of code have been changed. " +
            "Use the " +
            "<span class='button'>" + iconDecreaseIndentation + "</span> " +
            "<span class='button'>" + iconIncreaseIndentation + "</span> " +
            "buttons at the start of each line to change the indentation.";
    pyQuestion.questionMessage[pyQuestion.questionTypeDeleteLines] =
            "{number of lines} can be deleted. " + 
            "Click on the " +
            "<span class='button'>" + iconDelete + "</span> " +
            "button at the start of each line to delete it.";
    pyQuestion.questionMessage[pyQuestion.questionTypeChangeCode] =
            "One line of code is shown with a pink background. " + 
            "To change it click here: " +
            "<button id='changeCode'>Change code</button>";

    pyQuestion.questionMessage[pyQuestion.questionTypeChangeCodeWebDisplay] =
            "One line of code is shown with a pink background. " + 
            "To change it click here: " +
            "<button id='changeCode'>Change code</button>";

    pyQuestion.questionMessage[pyQuestion.questionHasRandomBehaviour] =
            "This program uses randomness, so you should run the target " + 
            "several times to see how that affects the result. " +
            "Also, when you have finished run your own program several times " +
            "to check its random behaviour. ";

    // Store the question type of this question
    let questionType = pyQuestion.questionTypeRandomOrder;

    // Creating 2 variables DO NOT EDIT
    let pyTargetSrc = "";
    let pyUserSrc =  "";

    // Store the list structure holding the code
    let listStructure = null;

    // Store the initial list structure for resetting
    let initialListStructure = $("<ul></ul>");

    // Store the CodeMirror instance for the user code
    let codeMirrorInstance = null;

    // Store the options of the module
    let options = {};

    // Store the default options of the module
    let defaults = {
        showListLineNumbers: false,
        highlightRow: true,
        deleteLinesNumberOfLines: "",
        changeCodeButtonId: "changeCode",
        changeCodeLineNumber: null,
        changeCodeBackgroundColor: [255, 225, 255],
        changeCodeCharLimit: 80,
        messageListId: "message",
        runTargetProgramButtonClass: "runTargetProgramButton",
        runUserProgramButtonClass: "runUserProgramButton",
        aboutButtonClass: "aboutButton",
        resetButtonClass: "resetButton",
        userCodeOutputAreaId: "userCodeArea",
        targetProgramOutputAreaId: "programOutputArea",
        userProgramOutputAreaId: "programOutputArea",
        targetTurtleOutputAreaId: "turtleGraphicsOutputForTarget",
        userTurtleOutputAreaId: "turtleGraphicsOutputForUser",
    };

    /*
     * Init the module
     */
    pyQuestion.init = function(type, pyTargetSrcEnc, pyUserSrcEnc, opts = {}) {
        options = $.extend({}, defaults, opts || {});

        questionType = type;

        // Decode the Python code
        pyTargetSrc = createPythonCodeFromString(pyTargetSrcEnc);
        pyUserSrc   = createPythonCodeFromString(pyUserSrcEnc);

        listStructure = $("#codeList");

        // Apply line numbers
        if (options.showListLineNumbers) {
            listStructure.addClass("lineNumbers");
        }

        // Put the user program to a list
        convertPythonCodeToList(pyUserSrc);

        // Store the initial list structure
        initialListStructure.prepend(listStructure.children().clone(true));

        // Show the default message for the question types
        let messageList = $("#message");
        if (messageList.length) {
            if (questionType & pyQuestion.questionTypeRandomOrder)
                messageList.append($("<li>" + pyQuestion.questionMessage[pyQuestion.questionTypeRandomOrder] + "</li>"));
            if (questionType & pyQuestion.questionTypeIndentation)
                messageList.append($("<li>" + pyQuestion.questionMessage[pyQuestion.questionTypeIndentation] + "</li>"));
            if (questionType & pyQuestion.questionTypeDeleteLines) {
                let message = pyQuestion.questionMessage[pyQuestion.questionTypeDeleteLines];
                if (Number.isInteger(options.deleteLinesNumberOfLines)) {
                    if (options.deleteLinesNumberOfLines > 1)
                        message = message.replace("{number of lines}",
                            options.deleteLinesNumberOfLines + " lines of code");
                    else
                        message = message.replace("{number of lines}",
                            options.deleteLinesNumberOfLines + " line of code");
                }
                else
                    message = message.replace("{number of lines}",
                        "Some of the code");
                messageList.append($("<li>" + message + "</li>"));
            }
            if (questionType & pyQuestion.questionTypeChangeCode)
                messageList.append($("<li>" + pyQuestion.questionMessage[pyQuestion.questionTypeChangeCode] + "</li>"));
            if (questionType & pyQuestion.questionTypeChangeCodeWebDisplay)
                messageList.append($("<li>" + pyQuestion.questionMessage[pyQuestion.questionTypeChangeCodeWebDisplay] + "</li>"));
            if (questionType & pyQuestion.questionHasRandomBehaviour)
                messageList.append($("<li>" + pyQuestion.questionMessage[pyQuestion.questionHasRandomBehaviour] + "</li>"));
        }

        // Configure the output textarea
        if (typeof CodeMirror === "undefined") {
            let userCodeOutputArea = $("#" + options.userCodeOutputAreaId);
            if (userCodeOutputArea.length) userCodeOutputArea.attr('readonly','readonly');
        }
        let targetProgramOutputArea = $("#" + options.targetProgramOutputAreaId);
        if (targetProgramOutputArea.length) targetProgramOutputArea.attr('readonly','readonly');
        let userProgramOutputArea = $("#" + options.userProgramOutputAreaId);
        if (userProgramOutputArea.length) userProgramOutputArea.attr('readonly','readonly');

        // Setup the event handlers
        pyQuestion.setupEventHandlers();
    }

    /*
     * Run the target program
     */
    pyQuestion.runTargetProgram = function(programOutputAreaId, turtleGraphicsOutputAreaId) {
        runPythonProgram(pyTargetSrc, programOutputAreaId, turtleGraphicsOutputAreaId);
    }

    /*
     * Run the user program
     */
    pyQuestion.runUserProgram = function(userCodeOutputAreaId, programOutputAreaId, turtleGraphicsOutputAreaId) {
        // Extract Python code from list
        let pySrc = createPythonCodeFromList();

        // Show the code
        let userCodeOutputArea = $("#" + userCodeOutputAreaId);
        if (userCodeOutputArea.length) {
            // if CodeMirror is enabled
            if (typeof CodeMirror !== "undefined") {
                if (codeMirrorInstance) {
                    codeMirrorInstance.getDoc().setValue(pySrc);
                }
                else {
                    userCodeOutputArea.text(pySrc);

                    codeMirrorInstance = CodeMirror.fromTextArea(
                        userCodeOutputArea.get(0), {
                            lineNumbers: true,
                            readOnly: true,
                            mode: "python",
                            theme: "idle"
                        });
                }
            }
            // using plain textarea
            else {
                userCodeOutputArea.text(pySrc);
            
                // Now resize the text area to fit the code 
                userCodeOutputArea.height("2px");
                userCodeOutputArea.height(userCodeOutputArea.get(0).scrollHeight);
            }
        }

        runPythonProgram(pySrc, programOutputAreaId, turtleGraphicsOutputAreaId);
    }

    /*
     * Reset the question
     */
    pyQuestion.resetQuestion = function() {
        if (confirm(resetMessage)) {
            /* Change to page reload
            // Restore the initial list structure
            listStructure.empty();
            listStructure.prepend(initialListStructure.children().clone(true));

            pyQuestion.setupCodeAreaEventHandlers();
            */
            window.location.reload();
        }
    }

    /*
     * Run a Python program using Skulpt
     */
    function runPythonProgram(pySrc, programOutputAreaId, turtleGraphicsOutputAreaId) {
        let programOutputArea = $("#" + programOutputAreaId);
        if (programOutputArea.length) {
            programOutputArea.css("color", "black"); // Show any program printed output in black, maybe it was red (error) before
            programOutputArea.html("");
        }

        // Now do the 'Python in web page' execution things
        Sk.pre = programOutputAreaId;
        Sk.configure({
            output: function(text) {
                if (programOutputArea.length) programOutputArea.append(text);
            },
            read: function(index) {
                if (Sk.builtinFiles === undefined || Sk.builtinFiles["files"][index] === undefined)
                    throw "File not found: '" + index + "'";
                return Sk.builtinFiles["files"][index];
            },
            inputfun: function(text) {
                Sk.output(text);
                let value = window.prompt(text);
                if (value == null) {
                    Sk.output("None\n");
                    return Sk.builtin.none.none$;
                }
                else {
                    Sk.output(value + "\n");
                    return value;
                }
            },
            inputfunTakesPrompt: true,
            __future__: Sk.python3
        }); 
        (Sk.TurtleGraphics || (Sk.TurtleGraphics = {})).target = turtleGraphicsOutputAreaId;
    
        let turtleGraphicsOutputArea = $("#" + turtleGraphicsOutputAreaId);
        if (turtleGraphicsOutputArea.length) {
            Sk.TurtleGraphics.width = turtleGraphicsOutputArea.width();
            Sk.TurtleGraphics.height = turtleGraphicsOutputArea.height();
        }
            
        let myPromise = Sk.misceval.asyncToPromise(function() {
            return Sk.importMainWithBody("<stdin>", false, pySrc, true);
        });
        myPromise.then(function(mod) {
            /*
            if (turtleGraphicsOutputArea.length)
                turtleGraphicsOutputArea.focus();
            */
            console.log('The program was executed successfully!');
        },
        function(err) {
            console.log(err.toString());
            if (programOutputArea.length) {
                programOutputArea.css("color", "red"); // Show error in red
                programOutputArea.text(err.toString());
            }
        });
    }

    /*
     * Setup the event handlers for the code area
     */
    pyQuestion.setupCodeAreaEventHandlers = function() {
        // If this is a 'random order' task, make the list drag-and-droppable
        if (questionType & pyQuestion.questionTypeRandomOrder) {
            $("#codeList").sortable();
            $("#codeList").disableSelection();
        }

        // If this is a 'indentation' task, add behaviour so that
        // the user clicks on the arrows to change indentation
        if (questionType & pyQuestion.questionTypeIndentation) {
            $("span.decreaseIndentation").off().on("click", function(e) {
                decreasePythonIndentation(e);  
            });
            $("span.increaseIndentation").off().on("click", function(e) {
                increasePythonIndentation(e);  
            });
        }

        // If this is a 'delete the code' task, add behaviour so that when 
        // the user clicks on the DEL span it will disappear
        if (questionType & pyQuestion.questionTypeDeleteLines) {
            $("span.delete").off().on("click", function(e) {
                if ($(this).parent().hasClass("changeCodeTarget")) {
                    alert("You may change this line of code. You cannot delete it.");
                }
                else
                    $(this).parent().remove();
            });
        }

        // If this is a 'change the line' task (either of the two varieties)
	// then we add a behaviour so that
        // the user clicks on the line to change the code content
        if ((questionType & pyQuestion.questionTypeChangeCode) || (questionType & pyQuestion.questionTypeChangeCodeWebDisplay)) {
		let sendToServer=questionType & pyQuestion.questionTypeChangeCodeWebDisplay;

            let id = options.changeCodeButtonId;
            $("#" + id).off().on("click", function(e) {
                changeLineContent(e, sendToServer);  
            });
        }

        fixTouchEventHandlers();
    }

    /*
     * Setup the event handlers
     */
    pyQuestion.setupEventHandlers = function() {
        // Setup the event handlers for the code area
        pyQuestion.setupCodeAreaEventHandlers();

        // Setup event handler for the run target code button
        let button = $("." + options.runTargetProgramButtonClass);
        if (button.length) {
            button.off().on("click", function() {
                pyQuestion.runTargetProgram(options.targetProgramOutputAreaId,
                                            options.targetTurtleOutputAreaId);
            });
        }

        // Setup event handler for the run user code button
        button = $("." + options.runUserProgramButtonClass);
        if (button.length) {
            button.off().on("click", function() {
                pyQuestion.runUserProgram(options.userCodeOutputAreaId,
                                          options.userProgramOutputAreaId,
                                          options.userTurtleOutputAreaId);
            });
        }

        // Setup event handler for the reset button
        button = $("." + options.resetButtonClass);
        if (button.length) {
            button.off().on("click", function() {
                let userCodeOutputArea = $("#" + options.userCodeOutputAreaId);
                if (userCodeOutputArea.length) userCodeOutputArea.text("");
                pyQuestion.resetQuestion();
            });
        }

        // Setup event handler for the about button
        button = $("." + options.aboutButtonClass);
        if (button.length) {
            button.off().on("click", function() {
                alert(aboutMessage);
            });
        }
    }

    /*
     * Fix the touch devices event handling
     */
    function fixTouchEventHandlers() {
        function touchHandler(event) {
            let touch = event.changedTouches[0];

            let simulatedEvent = document.createEvent("MouseEvent");
            simulatedEvent.initMouseEvent({
                    touchstart: "mousedown",
                    touchmove: "mousemove",
                    touchend: "mouseup"
                } [event.type], true, true, window, 1,
                touch.screenX, touch.screenY,
                touch.clientX, touch.clientY, false,
                false, false, false, 0, null);

            touch.target.dispatchEvent(simulatedEvent);
        }

        document.addEventListener("touchstart", touchHandler, { capture: true, passive: true });
        document.addEventListener("touchmove", touchHandler, { capture: true, passive: true });
        document.addEventListener("touchend", touchHandler, { capture: true, passive: true });
        document.addEventListener("touchcancel", touchHandler, { capture: true, passive: true });
    }

    /*
     * Increase Python indentation of the current line
     */
    function increasePythonIndentation(event) {
        increaseOrDecreasePythonIndentation(event, true); // true means increase
    }

    /*
     * Increase Python indentation of the current line
     */
    function decreasePythonIndentation(event) {
        increaseOrDecreasePythonIndentation(event, false); // false means decrease    
    }

    /*
     * Increase or decrease the Python indentation of the current line
     */
    function increaseOrDecreasePythonIndentation(event, increasePythonIndentationFlag) {
        let target = $(event.target);
        let thisLi = target.parent();
        let thisSpan = thisLi.find("span.indentation");
        let thisSpacing = thisSpan.text();

        // Replace unicode space with a regular space
        thisSpacing = thisSpacing.replace(unicodeSpaceRegex, " ");

        if (increasePythonIndentationFlag) { 
            // Increase Python indentation
            thisSpacing = "    " + thisSpacing; // Apply indentation on the left
        }
        else {
            // Decrease Python indentation
            if (thisSpacing.substring(0, 4) == "    ") {
                thisSpacing = thisSpacing.substring(4);
            }
        }

        thisSpan.html(thisSpacing.replaceAll(" ", "&nbsp;"));
    }


    /*
     * Send the newly entered line of code to the server
     */
    function sendNewLineOfCodeToServer(lineOfCode) {

    var destinationURL = "https://cgi.cse.ust.hk/~rossiter/cgi-bin/1021_lecture_student_input/storeInputFromStudent.php"; 
    var showMessage = true;

	lineOfCode=lineOfCode.trim();	// Dump any whitespace at the start or end of the string
	lineOfCode=encodeURIComponent(lineOfCode); // Encode appropriately for URL

	var thisFileLocation=encodeURIComponent(window.location.pathname);
	var textToTransmit="from=" + thisFileLocation + "code=" + lineOfCode ;

    $.ajax({
           type: "GET",
           url: destinationURL,
           data: textToTransmit, 
           dataType: "text",
           success: function(data) {
               if (showMessage) console.log("The form data has been submitted, it was " + textToTransmit);
           },
           error: function() { 
               if (showMessage) console.log("FAILED to submit the form data!");
           }
         });

    }

	let previousLineOfCode=""; // Each time a line of code is entered, if it is the same as before do nothing

    /*
     * Change the code content
     */
    function changeLineContent(event, sendToServer) {
        let thisLi = $(".changeCodeTarget");
        
        // Get the code content (without indentation)
        let thisCodeContentSpan = thisLi.find("span.codeContent");

        // Ask for the replacement
        let newLineOfCode = prompt("What is the new line of code?\n\n(The indentation will be the same as now).",
                                   thisCodeContentSpan.text());

        // Show a warning when the line of code is longer than the limit
        if (newLineOfCode.length > options.changeCodeCharLimit) {
            alert("Your new line of code is too long (>" +
                  options.changeCodeCharLimit + " characters).\n" +
                  "Please use a shorter line of code.");
        }
        
        // The user must enter a new line of code <= 80 characters (default: 80)
        // and the line of code must be different to the previous line of code entered
        if ( (newLineOfCode.length <= options.changeCodeCharLimit) && 
             (newLineOfCode != previousLineOfCode) ) { 

            console.log("This is a new line of code");

            if (newLineOfCode != null) { // If the user enters nothing, it returns null
                thisCodeContentSpan.text(newLineOfCode);
            }    

            if (sendToServer) {
                //alert("Will send " + newLineOfCode + " to server");
                sendNewLineOfCodeToServer(newLineOfCode);
            }

            previousLineOfCode = newLineOfCode;
        }
    }


    /*
     * Create the Python code from encoded string
     */
    function createPythonCodeFromString(encodedCode) {
        // Decode base-64 encoded string to ascii
        return(atob(encodedCode));
    }

    /*
     * Convert the Python code to a list structure
     */
    function convertPythonCodeToList(pythonCode) {
        // Split the code into lines
        let pythonLines = pythonCode.split("\n");

        // For each line of code, need to use javascript to build something like this:  
        //   <li><span>...</span>import turtle</li>

        // Go through each individual line of Python code
        pythonLines.forEach(function(pythonLine, lineNumber) { 
            // Create the content of the drag and drop list
            let thisLi = $("<li></li>");

            // Adjust the indentation for indentation question type
            if (questionType & pyQuestion.questionTypeIndentation) {
                let decision = Math.floor(Math.random() * 3); // makes 0 or 1 or 2

                // if decision == 0 then do nothing
                // if decision == 1 then increase indentation
                if (decision == 1) {
                    // Add 4 spaces at the start
                    pythonLine = "    " + pythonLine;
                }
                // if decision == 2 then decrease indentation
                else if (decision == 2) {
                    // Replace unicode space with a regular space
                    pythonLine = pythonLine.replace(unicodeSpaceRegex, " ");

                    // If have one indentation, decrease it
                    if (pythonLine.substring(0, 4) == "    ") {
                        pythonLine = pythonLine.substring(4);
                    }
                }
            }

            // Random order question
            if (questionType & pyQuestion.questionTypeRandomOrder) {
                // Add the icon as a span
                thisLi.append($("<span class='move'>" + iconRandomOrder + "</span>"));
            }

            // Indentation question
            if (questionType & pyQuestion.questionTypeIndentation) {
                // Add the left and right icons as spans
                thisLi.append($("<span class='button decreaseIndentation'>" + iconDecreaseIndentation + "</span>"));
                thisLi.append($("<span class='button increaseIndentation'>" + iconIncreaseIndentation + "</span>"));
            }

            // Delete code question
            if (questionType & pyQuestion.questionTypeDeleteLines) {
                // Add the delete icon as span
                thisLi.append($("<span class='button delete'>" + iconDelete + "</span>"));
            }

            // Change code question, this goes after the code
            if ((questionType & pyQuestion.questionTypeChangeCode) || (questionType & pyQuestion.questionTypeChangeCodeWebDisplay)) {
                if (options.changeCodeLineNumber == lineNumber + 1) {
                    // If this is a 'change a line of code' task of a particular line
                    // change the background colour of the relevant line of code
                    // so the user can easily see which line of code to change		
                    thisLi.css("background-color", "rgb(" + options.changeCodeBackgroundColor.join(",") + ")");
                    thisLi.addClass("changeCodeTarget");
                }
            }

            // Replace the spaces with &nbsp;
            let pythonCodeContent = replacePythonSpacesOnLeftWithNBSP(pythonLine);
            thisLi.append("<span class='indentation'>" + pythonCodeContent[0] + "</span>"); // Add the spacing
            thisLi.append("<span class='codeContent'>" + pythonCodeContent[1] + "</span>"); // Add the code content

            let index = listStructure.children().length;
            // Randomize the position for random order question type
            if (questionType & pyQuestion.questionTypeRandomOrder) {
                index = Math.floor(Math.random() * (listStructure.children().length + 1));
            }

            // Add the highlight class if row highlight is enabled
            if (options.highlightRow) {
                thisLi.addClass("highlight");
            }

            if (index == listStructure.children().length) {
                // Add code to the end of the list
                listStructure.append(thisLi);
            }
            else
                listStructure.children().eq(index).before(thisLi);
        });
    }

    /*
     * Replace any spaces on the left of Python code with &nbsp;
     */
    function replacePythonSpacesOnLeftWithNBSP(pythonLine) {
        // Replace any spaces on the left with &nbsp;
        let NBSPContent = "";
        let index = 0;

        // Replace any unicode space with a regular space
        pythonLine = pythonLine.replace(unicodeSpaceRegex, ' ');

        let finishedProcessingStart = false;
        while (!finishedProcessingStart) {
            if (pythonLine.charAt(index) == " ") {
                NBSPContent += "&nbsp;";
                index++;
            } else {
                finishedProcessingStart = true; // Stop loop if we encounter a non-space character
            }
        }

        // Return the spaces and code content separately
        return [NBSPContent,  pythonLine.substring(index, pythonLine.length)];
    }

    /*
     * Create Python code from the list structure
     */
    function createPythonCodeFromList() {
        let completePythonCodeFromList = "";
    
        listStructure.find("li").each(function() {
            let thisLi = $(this);
            let thisLine = thisLi.find("span.indentation").text() + 
                           thisLi.find("span.codeContent").text();
            // Replace unicode space with a regular space
            thisLine = thisLine.replace(unicodeSpaceRegex, " ");

            completePythonCodeFromList += thisLine + "\n";
        });

        // Remove last newline
        completePythonCodeFromList = completePythonCodeFromList.substring(0, completePythonCodeFromList.length - 1);

        return completePythonCodeFromList;
    }

}(window.pyQuestion = window.pyQuestion || {}));
