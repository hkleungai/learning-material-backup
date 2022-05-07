var debugDisplayLineNumber = false;
var mazeBuffer, mazeVisited;

var defaultWidth = 19;
var defaultHeight = 19;

function resetValue() {
  var handle = $("#custom-handle");
  var handle2 = $("#custom-handle2");

  $("#slider").slider("value", defaultWidth);
  $("#slider2").slider("value", defaultHeight);

  handle.text(defaultWidth);
  handle2.text(defaultHeight);
}

function genemptyMaps(width, height) {
  var maps = [];
  for (var j = 1; j <= height; j = j + 1) {
    var tmp = []
    for (var i = 1; i <= width; i = i + 1) {
      tmp.push("B");
    };
    maps.push(tmp);
  }
  return maps;
}

function genemptyBoolMaps(width, height) {
  var maps = [];
  for (var j = 1; j <= height; j = j + 1) {
    var tmp = []
    for (var i = 1; i <= width; i = i + 1) {
      tmp.push(0);
    };
    maps.push(tmp);
  }
  return maps;
}

function onBoundary(x, y, width, height) {

  if (x <= 0 || y <= 0 || x >= width - 1 || y >= height - 1)
    return true;

  return false;
}

//Generate for 1 path
function generateMazeMapRecurisve(r, c, width, height) {
  mazeVisited[r][c] = 1;

  mazeBuffer[r][c] = " ";


  var roffset = [-2, 2, 0, 0];

  var coffset = [0, 0, -2, 2];

  var tmpIndexFrom, tmpIndexTo, tmp;

  for (var i = 0; i < 10; i++) {

    tmpIndexFrom = Math.floor(Math.random() * 4);

    tmpIndexTo = Math.floor(Math.random() * 4);


    tmp = roffset[tmpIndexFrom];

    roffset[tmpIndexFrom] = roffset[tmpIndexTo];

    roffset[tmpIndexTo] = tmp;


    tmp = coffset[tmpIndexFrom];

    coffset[tmpIndexFrom] = coffset[tmpIndexTo];

    coffset[tmpIndexTo] = tmp;


  }

  for (var i = 0; i < 4; i++) {


    var curRow = r + roffset[i];

    var curCol = c + coffset[i];
    if (!onBoundary(curCol, curRow, width, height)) {
      if (mazeVisited[curRow][curCol] == 0) {
        mazeBuffer[(r + curRow) / 2][(c + curCol) / 2] = " ";

        generateMazeMapRecurisve(curRow, curCol, width, height);
      }
    }
  }
}


function generateMazeMap(width, height) {
  // Build up the map...

  mazeBuffer = genemptyMaps(width, height);

  // Generate the number from 1..23

  var xIndex = Math.floor(width / 2);
  var yIndex = Math.floor(height / 2);


  mazeBuffer[yIndex][xIndex] = " ";


  mazeVisited = genemptyBoolMaps(width, height);
  generateMazeMapRecurisve(yIndex, xIndex, width, height);

  return mazeBuffer;
}

function ifItisSpace(x, y, givenMap) {
  height = givenMap.length;
  if (height == 0)
    return false;
  width = givenMap[0].length;
  if (x <= 0 || x >= width - 1 || y <= 0 || y >= height - 1) return false;
  if (givenMap[y][x] == " ") return true;
  return false;
}

function checkPassable(x, y, givenMap) {
  var left = ifItisSpace(x - 1, y, givenMap);
  var right = ifItisSpace(x + 1, y, givenMap);
  var up = ifItisSpace(x, y - 1, givenMap);
  var down = ifItisSpace(x, y + 1, givenMap);
  if (left || right || up || down) return true;
  else return false;
}

function checkDoubleMap(maps, width, height, timeMax) {
  var h1 = true;
  var h2 = true;
  var v1 = true;
  var v2 = true;
  var h1num = height;
  var h2num = height;
  var v1num = width;
  var v2num = width;

  for (var i = 1; i < width - 1; i++) {
    var times = 0;
    for (; times < timeMax && maps[times][i] == "B"; times++) {
    }
    // console.log("v1times",times);
    v1num = Math.min(times, v1num);
    var times = 0;
    for (; times < timeMax && maps[height - 1 - times][i] == "B"; times++) {
    }
    // console.log("v2times",times);
    v2num = Math.min(times, v2num);
    if (maps[0][i] == "B" && maps[1][i] != "B") v1 = false;
    if (maps[height - 2][i] != "B" && maps[height - 1][i] == "B") v2 = false;
    // console.log(maps[0][i],maps[1][i],maps[height-2][i],maps[height-1][i],"v1v2",v1,v2);
  }
  for (var j = 1; j < height - 1; j++) {
    var times = 0;
    for (; times < timeMax && maps[j][times] == "B"; times++) {
    }
    // console.log("h1times",times);
    h1num = Math.min(times, h1num);
    var times = 0;
    for (; times < timeMax && maps[j][width - 1 - times] == "B"; times++) {
    }
    // console.log("h2times",times);
    h2num = Math.min(times, h2num);
    if (maps[j][0] == "B" && maps[j][1] != "B") h1 = false;
    if (maps[j][width - 2] != "B" && maps[j][width - 1] == "B") h2 = false;
    // console.log(maps[j][0],maps[j][1],maps[j][width-2],maps[j][width-1],"h1h2",h1,h2);
  }
  // console.log(v1,v2,h1,h2,h1num,h2num,v1num,v2num);
  if (h2) {
    for (var times = h2num - 1; times > 0; times--) {
      for (var j = 1; j < height - 1; j = j + 1) {
        
        if (maps[j][width - 1 - times - 1] == " " && maps[j][width - 1 - times - 1 - 1] == "B") {
          maps[j][width - times - 1] = "B";
        }
        else
          maps[j][width - times - 1] = maps[j][width - 1 - times - 1];
      }
    }
  }
  if (v2) {
    for (var times = v2num - 1; times > 0; times--) {
      for (var i = 1; i < width - 1; i = i + 1) {
        
        if (maps[height - times - 1 - 1][i] == " " && maps[height - times - 1 - 1 - 1][i] == "B") {
          maps[height - times - 1][i] = "B";
        }
        else
          maps[height - times - 1][i] = maps[height - times - 1 - 1][i];
      }
    }
  }
  if (h1) {
    for (var times = h1num - 1; times > 0; times--) {
      for (var j = 1; j < height - 1; j = j + 1) {
        
        if (maps[j][times + 1] == " " && maps[j][times + 1 + 1] == "B") {
          maps[j][times] = "B";
        }
        else
          maps[j][times] = maps[j][times + 1];
      }
    }
  }
  if (v1) {
    for (var times = v1num - 1; times > 0; times--) {
      for (var i = 1; i < width - 1; i = i + 1) {
        
        if (maps[times + 1][i] == " " && maps[times + 1 + 1][i] == "B") {
          maps[times][i] = "B";
        }
        else
          maps[times][i] = maps[times + 1][i];
      }
    }
  }
}

function genmap() {
  var width = $("#slider").slider("option", "value");
  var height = $("#slider2").slider("option", "value");
  var typeOfMap = $("input[name='tasks']:checked").val();

  genmapWithArgs(width, height, typeOfMap)
}

function genmapWithArgs(width, height, typeOfMap) {
  if (typeOfMap == undefined) {
    alert("Please choose the task first");
    return;
  }
  var maps = genemptyMaps(width, height);

  playerx = Math.floor(Math.random() * (width - 2)) + 1;

  if (typeOfMap == 4) {
    maps = generateMazeMap(width, height);
    // checkDoubleMap(maps, width, height,3);
    do {
      playerx = Math.floor(Math.random() * (width - 2)) + 1;
      playery = Math.floor(Math.random() * (height - 2)) + 1;

    } while (maps[playery][playerx] != " ");
    var exitx, exity;

    var trialMax = (width + height - 4)
    var trial = 0;
    do {
      chooseside = Math.floor(Math.random() * (4));
      trial = trial + 1;

      if (chooseside == 0) {
        exity = 0;
        exitx = Math.floor(Math.random() * (width - 2) + 1);
      }
      if (chooseside == 1) {
        exity = height - 1;
        exitx = Math.floor(Math.random() * (width - 2) + 1);
      }
      if (chooseside == 2) {
        exity = Math.floor(Math.random() * (height - 2) + 1);
        exitx = 0;
      }
      if (chooseside == 3) {
        exity = Math.floor(Math.random() * (height - 2) + 1);
        exitx = width - 1;
      }
      if (trial > trialMax) {
        //alert("It cannot be done, please choose another width and/or height.");
        if (chooseside == 0) {
          if (checkPassable(exitx, exity + 1, maps))
            maps[exity + 1][exitx] = " ";
        }
        if (chooseside == 1) {
          if (checkPassable(exitx, exity - 1, maps))
            maps[exity - 1][exitx] = " ";
        }
        if (chooseside == 2) {
          if (checkPassable(exitx + 1, exity, maps))
            maps[exity][exitx + 1] = " ";
        }
        if (chooseside == 3) {
          if (checkPassable(exitx - 1, exity, maps))
            maps[exity][exitx - 1] = " ";
        }
        break;
      }
    } while (!checkPassable(exitx, exity, maps));
    maps[exity][exitx] = "E";
  }

  if (typeOfMap == 0) {

    playery = Math.floor(Math.random() * (height - 2) + 1);

    for (var j = 1; j < height - 1; j = j + 1) {
      for (var i = 1; i < width - 1; i = i + 1) {
        maps[j][i] = " "
      };
    }
    maps[0][playerx] = "E";
  }
  if (typeOfMap == 1) {
    playerx = Math.floor(Math.random() * (width - 3)) + 1;
    playery = Math.floor(Math.random() * (height - 2) + 1);

    for (var j = 1; j < height - 1; j = j + 1) {
      for (var i = 1; i < width - 1; i = i + 1) {
        maps[j][i] = " "
      };
    }
    // Pick a random exit at the top
    maps[0][playerx + Math.floor(Math.random() * (width - 2 - playerx) + 1)] = "E";
  }

  if (typeOfMap == 2) {
    playery = Math.floor(Math.random() * (height - 2) + 1);

    for (var j = 1; j < height - 1; j = j + 1) {
      for (var i = 1; i < width - 1; i = i + 1) {
        maps[j][i] = " "
      };
    }
    // Pick a random exit at the top
    maps[0][Math.floor(Math.random() * (width - 2) + 1)] = "E";
  }

  if (typeOfMap == 3) {
    rowsToBreak = []
    for (var j = height - 2; j >= 1; j = j - (Math.floor(Math.random() * 4) + 1)) {
      rowsToBreak.push(j)
      j = j - 1;
    };
    rowsToBreak.push(-1);
    rowsToBreak = rowsToBreak.reverse();
    previousRow = rowsToBreak.pop();
    nextHandled = rowsToBreak.pop();

    // Player will always be the last block of the maze
    playery = nextHandled + Math.floor(Math.random() * (height - 2 - nextHandled - 1) + 2);


    while (nextHandled !== undefined) {
      for (var j = previousRow; j > nextHandled + 1; j = j - 1) {
        for (var i = 1; i < width - 1; i = i + 1) {
          maps[j][i] = " "
        };
      }
      if (nextHandled > 0) {
        random_x = Math.floor(Math.random() * (width - 2) + 1);
        maps[nextHandled + 1][Math.floor(Math.random() * (width - 2) + 1)] = " ";
      }
      previousRow = nextHandled;
      nextHandled = rowsToBreak.pop();
    }
    // Pick a random exit at the top
    maps[0][Math.floor(Math.random() * (width - 2) + 1)] = "E";

  }
  maps[playery][playerx] = "P";
  return maps;
}

function visualizeMap(maps) {
  var textoutput = "";
  var output = '"""\\\n';
  if (debugDisplayLineNumber) {
    for (var j = 0; j < maps.length; j = j + 1) {
      output += j.toString().padStart(2, "0") + ":" + maps[j].join("");
      textoutput += j.toString().padStart(2, "0") + ":" + maps[j].join("");
      if (j < maps.length - 1) {
        output += "<br>";
        textoutput += "\n";
      }
    };
  }
  else {
    for (var j = 0; j < maps.length; j = j + 1) {
      output += maps[j].join("");
      textoutput += maps[j].join("");
      if (j < maps.length - 1)
        output += "<br>";
      textoutput += "\n";
    };
  }

  var block = "<div class='Column' style='background-color:blue;'>&nbsp;</div>";
  var empty = "<div class='Column' style='background-color:white;'>&nbsp;</div>";
  var exit = "<div class='Column' style='background-color:red;'>&nbsp;</div>";
  var player = "<div class='Column' style='background-color:grey;'>&nbsp;</div>";

  output = "<div class='Row'>" + textoutput.replaceAll(" ", empty).replaceAll("\n", "</div><div class='Row'>");
  output = output.replaceAll("B", block).replaceAll("E", exit).replaceAll("P", player);
  output = output += "</div>"
  return output;
}