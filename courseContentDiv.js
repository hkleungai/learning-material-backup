var courseContentCells = document.querySelectorAll('td.course-content');
if (!courseContentCells) {
    throw new Error('No course titles can be found!!');
}
courseContentCells.forEach(function (cell) {
    var descriptionDiv = cell.querySelector('.course-description');
    if (!descriptionDiv) {
        throw new Error('No course descriptionDivs can be found!!');
    }
    var description = descriptionDiv.innerHTML;
    descriptionDiv.innerHTML = '';
    var triggerDiv = cell.querySelector('div.course-description-trigger');
    if (!triggerDiv) {
        throw new Error('No triggerDivs for course descriptionDivs can be found!!');
    }
    triggerDiv.addEventListener('click', function () {
        var isDescriptionActive = descriptionDiv.classList.toggle('active');
        triggerDiv.innerHTML = isDescriptionActive ? '➖' : '➕';
        descriptionDiv.innerHTML = isDescriptionActive ? description : '';
    });
});
