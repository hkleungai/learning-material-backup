var buildSemesterCell = function (code, semester) {
    var link = "".concat(code, " ").concat(semester).replace(/\s/g, '-');
    return (
    /* html */ "\n    <td style=\"width: 20%\">\n      <a href=\"".concat(link, "\">").concat(semester, "</a>\n    </td>\n    "));
};
var buildCourseRow = function (_a) {
    var code = _a.code, title = _a.title, semesters = _a.semesters;
    var _b = semesters.map(function (semester) { return buildSemesterCell(code, semester); }), firstCell = _b[0], extraCells = _b.slice(1);
    var firstRow = (
    /* html */ "\n    <tr>\n      <td style=\"width: 20%\" rowSpan=\"".concat(semesters.length, "\">").concat(code, "</td>\n      <td rowSpan=\"").concat(semesters.length, "\">").concat(title, "</td>\n      ").concat(firstCell, "\n    </tr>\n    "));
    var extraRows = extraCells.map(function (semester) { /* html */ return "<tr>".concat(semester, "</tr>"); });
    return "".concat(firstRow, "\n").concat(extraRows);
};
var buildCategoryTable = function (category, courses) { return (
/* html */ "\n  <div class=\"main-content\">\n    <h3 class=\"category\">".concat(category, "</h3>\n      <table class=\"course-list\">\n        <tr>\n          <th>Course Code</th>\n          <th>Course Title</th>\n          <th>Semester</th>\n        </tr>\n        ").concat(courses.map(buildCourseRow).join('\n'), "\n      </table>\n    </h3>\n  </div>\n  ")); };
var buildTable = function (categorizedCourses) { return (Object
    .entries(categorizedCourses)
    .map(function (props) { return buildCategoryTable.apply(void 0, props); })
    .join('\n')); };
