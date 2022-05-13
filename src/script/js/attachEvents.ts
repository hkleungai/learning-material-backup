const attachEvents = () => {
  const courseContentCells = document.querySelectorAll('td.course-content');
  if (!courseContentCells || !courseContentCells.length) {
    const error = 'No course titles can be found!!';
    alert(error);
    throw new Error(error);
  }
  courseContentCells.forEach(cell => {
    const descriptionDiv = cell.querySelector('div.course-description');
    if (!descriptionDiv) {
      const error = 'No descriptions can be found!!';
      alert(error);
      throw new Error(error);
    }
    const toggleDiv = cell.querySelector('div.course-description-toggle') as HTMLDivElement;
    if (!toggleDiv) {
      const error = 'No toggles for descriptions can be found!!';
      alert(error);
      throw new Error(error);
    }
    toggleDiv.addEventListener('click', () => {
      const isDescriptionActive = descriptionDiv.classList.toggle('course-description--active');
      toggleDiv.innerHTML = isDescriptionActive ? '➖' : '➕';
    })
  });
}
