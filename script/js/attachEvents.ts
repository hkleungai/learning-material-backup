const attachEvents = () => {
  const courseContentCells = document.querySelectorAll('td.course-content');
  if (!courseContentCells || !courseContentCells.length) {
    return throwError('No course titles can be found!!');
  }
  courseContentCells.forEach(cell => {
    const descriptionDiv = cell.querySelector('div.course-description');
    if (!descriptionDiv) {
      return throwError('No descriptions can be found!!');
    }
    const toggleDiv = cell.querySelector('div.course-description-toggle') as HTMLDivElement;
    if (!toggleDiv) {
      return throwError('No toggles for descriptions can be found!!');
    }
    toggleDiv.addEventListener('click', () => {
      const isDescriptionActive = descriptionDiv.classList.toggle('course-description--active');
      toggleDiv.innerHTML = isDescriptionActive ? '➖' : '➕';
    })
  });
}
