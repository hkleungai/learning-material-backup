var __assign = (this && this.__assign) || function () {
    __assign = Object.assign || function(t) {
        for (var s, i = 1, n = arguments.length; i < n; i++) {
            s = arguments[i];
            for (var p in s) if (Object.prototype.hasOwnProperty.call(s, p))
                t[p] = s[p];
        }
        return t;
    };
    return __assign.apply(this, arguments);
};
var buildSemesterCell = function (code, semester) {
    var link = "./".concat(code, " ").concat(semester, "/index.html").replace(/\s/g, '-');
    return (
    /* html */ "\n    <td class=\"course-semester\">\n      <a href=\"".concat(link, "\">").concat(semester, "</a>\n    </td>\n    "));
};
var buildCourseRow = function (_a) {
    var code = _a.code, description = _a.description, semesters = _a.semesters, title = _a.title;
    var _b = semesters.map(function (semester) { return buildSemesterCell(code, semester); }), firstCell = _b[0], extraCells = _b.slice(1);
    var firstRow = (
    /* html */ "\n    <tr>\n      <td\n        class=\"course-code\"\n        rowSpan=\"".concat(semesters.length, "\"\n      >\n        ").concat(code, "\n      </td>\n      <td\n        class=\"course-content\"\n        rowSpan=\"").concat(semesters.length, "\"\n      >\n        <div class=\"course-content\">\n          <div class=\"course-title\">\n            <div>").concat(title, "</div>\n            <div class=\"course-description-toggle\">\u2795</div>\n          </div>\n          <div class=\"course-description\">\n            <br/>\n            ").concat(description, "\n          </div>\n        </div>\n      </td>\n      ").concat(firstCell, "\n    </tr>\n    "));
    var rows = extraCells.map(function (semester) { /* html */ return "<tr>".concat(semester, "</tr>"); });
    rows.unshift(firstRow);
    return rows.join('\n');
};
var buildCategoryTable = function (category, courses) { return (
/* html */ "\n  <div class=\"category\">\n    <h3 class=\"category-title\">".concat(category, "</h3>\n      <table class=\"courses\">\n        <tr>\n          <th>Code</th>\n          <th>Title / Content</th>\n          <th>Semester</th>\n        </tr>\n        ").concat(courses.map(buildCourseRow).join('\n'), "\n      </table>\n    </h3>\n  </div>\n  ")); };
var buildTables = function (categorizedPreCourses, fetchedCourses) {
    var buildCourse = (function (_a) {
        var code = _a.code, semesters = _a.semesters;
        return (__assign(__assign({}, fetchedCourses[code]), { code: code, semesters: semesters }));
    });
    var tables = categorizedPreCourses.map(function (_a) {
        var category = _a.category, courses = _a.courses;
        return buildCategoryTable(category, courses.map(buildCourse));
    });
    return tables.join('\n');
};
