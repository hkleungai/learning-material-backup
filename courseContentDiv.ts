const courseContentCells = document.querySelectorAll('td.course-content');
if (!courseContentCells) {
  throw new Error('No course titles can be found!!');
}
courseContentCells.forEach(cell => {
  const descriptionDiv = cell.querySelector('.course-description');
  if (!descriptionDiv) {
    throw new Error('No course descriptionDivs can be found!!');
  }
  const description = descriptionDiv.innerHTML;
  descriptionDiv.innerHTML = '';

  const triggerDiv = cell.querySelector('div.course-description-trigger');
  if (!triggerDiv) {
    throw new Error('No triggerDivs for course descriptionDivs can be found!!');
  }
  triggerDiv.addEventListener('click', () => {
    const isDescriptionActive = descriptionDiv.classList.toggle('active');
    triggerDiv.innerHTML = isDescriptionActive ? '➖' : '➕';
    descriptionDiv.innerHTML = isDescriptionActive ? description : '';
  })
});
