var courseContentCells = document.querySelectorAll('td.course-content');
if (!courseContentCells) {
    throw new Error('No course titles can be found!!');
}
courseContentCells.forEach(function (cell) {
    var descriptionDiv = cell.querySelector('.course-description');
    if (!descriptionDiv) {
        throw new Error('No course descriptionDivs can be found!!');
    }
    var toggleDiv = cell.querySelector('div.course-description-toggle');
    if (!toggleDiv) {
        throw new Error('No toggleDivs for course descriptionDivs can be found!!');
    }
    toggleDiv.addEventListener('click', function () {
        var isDescriptionActive = descriptionDiv.classList.toggle('active');
        toggleDiv.innerHTML = isDescriptionActive ? '➖' : '➕';
    });
});
