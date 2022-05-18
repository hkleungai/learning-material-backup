var __classPrivateFieldGet = (this && this.__classPrivateFieldGet) || function (receiver, state, kind, f) {
    if (kind === "a" && !f) throw new TypeError("Private accessor was defined without a getter");
    if (typeof state === "function" ? receiver !== state || !f : !state.has(receiver)) throw new TypeError("Cannot read private member from an object whose class did not declare it");
    return kind === "m" ? f : kind === "a" ? f.call(receiver) : f ? f.value : state.get(receiver);
};
var _TableRenderer_instances, _TableRenderer_buildSemesterCell, _TableRenderer_buildCourseRow, _TableRenderer_buildCategorizedTable, _TableRenderer_attachCellEvent;
import BaseRenderer from './BaseRenderer.js';
export default class TableRenderer extends BaseRenderer {
    constructor(props) {
        super(props);
        _TableRenderer_instances.add(this);
    }
    ;
    ;
    ;
    build() {
        const categorizedTables = this.props.__CATEGORIZED_PRE_COURSES.map(({ category, courses }) => {
            const fullCourses = courses.map((course) => (Object.assign(Object.assign({}, course), this.props.__FETCHED_COURSES[course.code])));
            return __classPrivateFieldGet(this, _TableRenderer_instances, "m", _TableRenderer_buildCategorizedTable).call(this, category, fullCourses);
        });
        this.innerHTML = categorizedTables.join('\n');
        return this;
    }
    attachEvent() {
        const courseContentCells = this.fragment.querySelectorAll('td.course-content');
        if (!courseContentCells || !courseContentCells.length) {
            throw new Error('[ERROR]: No course titles can be found!');
        }
        courseContentCells.forEach(cell => __classPrivateFieldGet(this, _TableRenderer_instances, "m", _TableRenderer_attachCellEvent).call(this, cell));
        return this;
    }
}
_TableRenderer_instances = new WeakSet(), _TableRenderer_buildSemesterCell = function _TableRenderer_buildSemesterCell(code, semester) {
    const link = `./${code} ${semester}/index.html`.replace(/\s/g, '-');
    return (`
      <td class="course-semester">
        <a href="${link}">${semester}</a>
      </td>
      `);
}, _TableRenderer_buildCourseRow = function _TableRenderer_buildCourseRow({ code, description, semesters, title }) {
    const cells = semesters.map(semester => __classPrivateFieldGet(this, _TableRenderer_instances, "m", _TableRenderer_buildSemesterCell).call(this, code, semester));
    const [firstCell, ...extraCells] = cells;
    const firstRow = (`
      <tr>
        <td
          class="course-code"
          rowSpan="${semesters.length}"
        >
          ${code}
        </td>
        <td
          class="course-content"
          id="${encodeURIComponent(code + '' + title)}"
          rowSpan="${semesters.length}"
        >
          <div class="course-content">
            <div class="course-title">
              <div>${title}</div>
              <div class="course-description-toggle">➕</div>
            </div>
            <div class="course-description">
              <br/>
              ${description}
            </div>
          </div>
        </td>
        ${firstCell}
      </tr>
      `);
    const rows = extraCells.map(semester => `<tr>${semester}</tr>`);
    rows.unshift(firstRow);
    return rows.join('\n');
}, _TableRenderer_buildCategorizedTable = function _TableRenderer_buildCategorizedTable(category, courses) {
    return (`
      <div class="category">
        <h3 class="common-title" id="${encodeURIComponent(category)}">
          ${category}
        </h3>
        <table class="courses">
          <tr>
            <th>Code</th>
            <th>Title / Content</th>
            <th>Semester</th>
          </tr>
          ${courses.map(course => __classPrivateFieldGet(this, _TableRenderer_instances, "m", _TableRenderer_buildCourseRow).call(this, course)).join('\n')}
        </table>
      </div>
      `);
}, _TableRenderer_attachCellEvent = function _TableRenderer_attachCellEvent(cell) {
    const description = cell.querySelector('div.course-description');
    if (!description) {
        throw new Error('[ERROR]: No description div can be found!');
    }
    const toggle = cell.querySelector('div.course-description-toggle');
    if (!toggle || !(toggle instanceof HTMLDivElement)) {
        throw new Error('[ERROR]: No toggle div for descriptions can be found!');
    }
    toggle.onclick = () => {
        const isDescriptionActive = description.classList.toggle('course-description--active');
        const setToggleContent = () => {
            toggle.innerHTML = isDescriptionActive ? '➖' : '➕';
        };
        const timeout = +isDescriptionActive || 1000;
        setTimeout(setToggleContent, timeout);
    };
};
