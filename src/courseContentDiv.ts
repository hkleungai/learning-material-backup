const courseContentCells = document.querySelectorAll('td.course-content');
if (!courseContentCells) {
  throw new Error('No course titles can be found!!');
}
courseContentCells.forEach(cell => {
  const descriptionDiv = cell.querySelector('.course-description');
  if (!descriptionDiv) {
    throw new Error('No course descriptionDivs can be found!!');
  }
  const toggleDiv = cell.querySelector('div.course-description-toggle');
  if (!toggleDiv) {
    throw new Error('No toggleDivs for course descriptionDivs can be found!!');
  }
  toggleDiv.addEventListener('click', () => {
    const isDescriptionActive = descriptionDiv.classList.toggle('active');
    toggleDiv.innerHTML = isDescriptionActive ? '➖' : '➕';
  })
});
