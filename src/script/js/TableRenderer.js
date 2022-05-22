var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
var __classPrivateFieldGet = (this && this.__classPrivateFieldGet) || function (receiver, state, kind, f) {
    if (kind === "a" && !f) throw new TypeError("Private accessor was defined without a getter");
    if (typeof state === "function" ? receiver !== state || !f : !state.has(receiver)) throw new TypeError("Cannot read private member from an object whose class did not declare it");
    return kind === "m" ? f : kind === "a" ? f.call(receiver) : f ? f.value : state.get(receiver);
};
var _TableRenderer_instances, _TableRenderer_buildSemesterCell, _TableRenderer_buildCourseRow, _TableRenderer_buildTable, _TableRenderer_buildCategory, _TableRenderer_buildTableWithCategory, _TableRenderer_attachSingleDescriptionEvent, _TableRenderer_attachDescriptionEvent, _TableRenderer_attachSingleCopyLinkEvent, _TableRenderer_attachCopyLinkEvent;
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
            return __classPrivateFieldGet(this, _TableRenderer_instances, "m", _TableRenderer_buildTableWithCategory).call(this, category, fullCourses);
        });
        this.innerHTML = categorizedTables.join('\n');
        return this;
    }
    attachEvent() {
        __classPrivateFieldGet(this, _TableRenderer_instances, "m", _TableRenderer_attachDescriptionEvent).call(this);
        __classPrivateFieldGet(this, _TableRenderer_instances, "m", _TableRenderer_attachCopyLinkEvent).call(this);
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
}, _TableRenderer_buildTable = function _TableRenderer_buildTable(courses) {
    return (`
      <table class="courses">
        <tr>
          <th>Code</th>
          <th>Title / Content</th>
          <th>Semester</th>
        </tr>
        ${courses.map(course => __classPrivateFieldGet(this, _TableRenderer_instances, "m", _TableRenderer_buildCourseRow).call(this, course)).join('\n')}
      </table>
      `);
}, _TableRenderer_buildCategory = function _TableRenderer_buildCategory(category) {
    return (`
      <h3 class="common-title" id="${encodeURIComponent(category)}">
        ${category}
        <svg class="common-title-link" viewBox="0 0 16 16" version="1.1" width="16" height="16">
          <path
            fill-rule="evenodd"
            d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z">
          </path>
        </svg>
      </h3>
      `);
}, _TableRenderer_buildTableWithCategory = function _TableRenderer_buildTableWithCategory(category, courses) {
    return (`
      <div class="category">
        ${__classPrivateFieldGet(this, _TableRenderer_instances, "m", _TableRenderer_buildCategory).call(this, category)}
        ${__classPrivateFieldGet(this, _TableRenderer_instances, "m", _TableRenderer_buildTable).call(this, courses)}
      </div>
      `);
}, _TableRenderer_attachSingleDescriptionEvent = function _TableRenderer_attachSingleDescriptionEvent(cell) {
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
}, _TableRenderer_attachDescriptionEvent = function _TableRenderer_attachDescriptionEvent() {
    const courseContentCells = this.fragment.querySelectorAll('td.course-content');
    if (!courseContentCells || !courseContentCells.length) {
        throw new Error('[ERROR]: No course titles can be found!');
    }
    courseContentCells.forEach(cell => __classPrivateFieldGet(this, _TableRenderer_instances, "m", _TableRenderer_attachSingleDescriptionEvent).call(this, cell));
}, _TableRenderer_attachSingleCopyLinkEvent = function _TableRenderer_attachSingleCopyLinkEvent(title) {
    const svgLink = title.querySelector('svg.common-title-link');
    if (!svgLink || !(svgLink instanceof SVGElement)) {
        throw new Error('[ERROR]: No link element can be found!');
    }
    svgLink.onclick = () => __awaiter(this, void 0, void 0, function* () {
        try {
            const homeLink = window.location.href.replace(window.location.hash, '').replace(/\/+$/, '');
            const linkToBeCopied = `${homeLink}/#${title.id}`;
            yield navigator.clipboard.writeText(linkToBeCopied);
            alert('[SUCCESS]: Successfully copy the link');
        }
        catch (error) {
            throw new Error(error.message);
        }
    });
}, _TableRenderer_attachCopyLinkEvent = function _TableRenderer_attachCopyLinkEvent() {
    const titles = this.fragment.querySelectorAll('h3.common-title');
    if (!titles || !titles.length) {
        throw new Error('[ERROR]: No course titles can be found!');
    }
    titles.forEach(title => __classPrivateFieldGet(this, _TableRenderer_instances, "m", _TableRenderer_attachSingleCopyLinkEvent).call(this, title));
};
