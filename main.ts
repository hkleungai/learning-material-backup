const mainDiv = document.querySelector('div.main');
if (mainDiv) {
  mainDiv.innerHTML += buildTable(categorizedCourses);
}
