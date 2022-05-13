var attachEvents = function () {
    var courseContentCells = document.querySelectorAll('td.course-content');
    if (!courseContentCells || !courseContentCells.length) {
        var error = 'No course titles can be found!!';
        alert(error);
        throw new Error(error);
    }
    courseContentCells.forEach(function (cell) {
        var descriptionDiv = cell.querySelector('div.course-description');
        if (!descriptionDiv) {
            var error = 'No descriptions can be found!!';
            alert(error);
            throw new Error(error);
        }
        var toggleDiv = cell.querySelector('div.course-description-toggle');
        if (!toggleDiv) {
            var error = 'No toggles for descriptions can be found!!';
            alert(error);
            throw new Error(error);
        }
        toggleDiv.addEventListener('click', function () {
            var isDescriptionActive = descriptionDiv.classList.toggle('course-description--active');
            toggleDiv.innerHTML = isDescriptionActive ? '➖' : '➕';
        });
    });
};
