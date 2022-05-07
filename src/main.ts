const mainDiv = document.querySelector('div.main');
if (mainDiv) {
  mainDiv.innerHTML += buildTable(categorizedCourses);
  mainDiv.innerHTML += (
    /* html */`
    <h4 style="font-style: italic; text-align: end;">To Be Continued...</h3>
    `
  );
}
