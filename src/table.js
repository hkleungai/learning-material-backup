var buildCourseRow = function (_a) {
    var code = _a.code, title = _a.title, semester = _a.semester, link = _a.link;
    return (
    /* html */ "\n  <tr>\n    <td style=\"width: 20%\">".concat(code, "</td>\n    <td>").concat(title, "</td>\n    <td style=\"width: 20%\"><a href=\"").concat(link, "\">").concat(semester, "</a></td>\n  </tr>\n  "));
};
var buildCategoryTable = function (category, courses) { return (
/* html */ "\n  <div class=\"main-content\">\n    <h3 class=\"category\">".concat(category, "</h3>\n      <table class=\"course-list\">\n        <tr>\n          <th>Course Code</th>\n          <th>Course Title</th>\n          <th>Semester</th>\n        </tr>\n        ").concat(courses.map(buildCourseRow).join('\n'), "\n      </table>\n    </h3>\n  </div>\n  ")); };
var buildTable = function (categorizedCourses) { return (Object
    .entries(categorizedCourses)
    .map(function (props) { return buildCategoryTable.apply(void 0, props); })
    .join('\n')); };
