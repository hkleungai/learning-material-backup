var makeTemplate = function (content) {
    var template = document.createElement('template');
    template.innerHTML = content;
    if (!template.innerHTML || !template.innerHTML.length) {
        return throwError('No valid elements can be built!!');
    }
    return template.content;
};
var appendElements = function () {
    var mainDivClosingElement = document.querySelector('div.main h4.closing');
    if (!mainDivClosingElement) {
        return throwError('No header can be found on main div!!');
    }
    var noticeBoardFragment = makeTemplate(buildNoticeBoard(GIT_LOGS));
    mainDivClosingElement.before(noticeBoardFragment);
    var tableFragment = makeTemplate(buildTables(CATEGORIZED_PRE_COURSES, FETCHED_COURSES));
    mainDivClosingElement.before(tableFragment);
};
