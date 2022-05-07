var mainDiv = document.querySelector('div.main');
if (mainDiv) {
    mainDiv.innerHTML += buildTable(categorizedCourses);
    mainDiv.innerHTML += (
    /* html */ "\n    <h4 style=\"font-style: italic; text-align: end;\">To Be Continued...</h3>\n    ");
}
