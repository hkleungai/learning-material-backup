var attachEvents = function () {
    var courseContentCells = document.querySelectorAll('td.course-content');
    if (!courseContentCells || !courseContentCells.length) {
        return throwError('No course titles can be found!!');
    }
    courseContentCells.forEach(function (cell) {
        var descriptionDiv = cell.querySelector('div.course-description');
        if (!descriptionDiv) {
            return throwError('No descriptions can be found!!');
        }
        var toggleDiv = cell.querySelector('div.course-description-toggle');
        if (!toggleDiv) {
            return throwError('No toggles for descriptions can be found!!');
        }
        toggleDiv.addEventListener('click', function () {
            var isDescriptionActive = descriptionDiv.classList.toggle('course-description--active');
            toggleDiv.innerHTML = isDescriptionActive ? '➖' : '➕';
        });
    });
};
