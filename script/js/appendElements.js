var appendElements = function () {
    var mainDivHeader = document.querySelector('div.main h2.header');
    if (!mainDivHeader) {
        var error = 'No header can be found on main div!!';
        alert(error);
        throw new Error(error);
    }
    var template = document.createElement('template');
    template.innerHTML = buildTables(categorizedPreCourses, fetchedCourses);
    if (!template.innerHTML || !template.innerHTML.length) {
        var error = 'No valid html tables can be built!!';
        alert(error);
        template.remove();
        throw new Error(error);
    }
    mainDivHeader.after(template.content);
    template.remove();
};
