var buildSemesterCell = function (code, semester) {
    var link = "".concat(code, " ").concat(semester).replace(/\s/g, '-');
    return (
    /* html */ "\n    <td class=\"course-semester\">\n      <a href=\"".concat(link, "\">").concat(semester, "</a>\n    </td>\n    "));
};
var buildCourseRow = function (_a) {
    var code = _a.code, description = _a.description, semesters = _a.semesters, title = _a.title;
    var _b = semesters.map(function (semester) { return buildSemesterCell(code, semester); }), firstCell = _b[0], extraCells = _b.slice(1);
    var firstRow = (
    /* html */ "\n    <tr>\n      <td\n        class=\"course-code\"\n        rowSpan=\"".concat(semesters.length, "\"\n      >\n        ").concat(code, "\n      </td>\n      <td\n        class=\"course-content\"\n        rowSpan=\"").concat(semesters.length, "\"\n      >\n        <div class=\"course-content\">\n          <div class=\"course-title\">\n            <div>").concat(title, "</div>\n            <div class=\"course-description-toggle\">\u2795</div>\n          </div>\n          <div class=\"course-description\">\n            <br/>\n            ").concat(description, "\n          </div>\n        </div>\n      </td>\n      ").concat(firstCell, "\n    </tr>\n    "));
    var extraRows = extraCells.map(function (semester) { /* html */ return "<tr>".concat(semester, "</tr>"); });
    return "".concat(firstRow, "\n").concat(extraRows);
};
var buildCategoryTable = function (category, courses) { return (
/* html */ "\n  <div class=\"main-content\">\n    <h3 class=\"category\">".concat(category, "</h3>\n      <table class=\"course-list\">\n        <tr>\n          <th>Code</th>\n          <th>Title / Content</th>\n          <th>Semester</th>\n        </tr>\n        ").concat(courses.map(buildCourseRow).join('\n'), "\n      </table>\n    </h3>\n  </div>\n  ")); };
var buildTable = function (categorizedCourses) { return (categorizedCourses
    .map(function (_a) {
    var category = _a.category, courses = _a.courses;
    return buildCategoryTable(category, courses);
})
    .join('\n')); };
