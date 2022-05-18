import {
  Categorized,
  Course,
  FetchedCourses,
  PreCourse,
} from '../interface/types';
import BaseRenderer from './BaseRenderer';

interface TableRendererProps {
  __CATEGORIZED_PRE_COURSES: Categorized<PreCourse>[],
  __FETCHED_COURSES: FetchedCourses,
}
export default class TableRenderer extends BaseRenderer<TableRendererProps> {
  constructor(props: TableRendererProps) {
    super(props);
  }
  #buildSemesterCell(code: string, semester: string) {
    const link = `./${code} ${semester}/index.html`.replace(/\s/g, '-');
    return (
      /* html */`
      <td class="course-semester">
        <a href="${link}">${semester}</a>
      </td>
      `
    );
  };
  #buildCourseRow({ code, description, semesters, title }: Course): string {
    const cells = semesters.map(semester => this.#buildSemesterCell(code, semester));
    const [firstCell, ...extraCells] = cells;
    const firstRow = (
      /* html */`
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
      `
    );
    const rows = extraCells.map(semester => /* html */`<tr>${semester}</tr>`);
    rows.unshift(firstRow);
    return rows.join('\n');
  };
  #buildCategorizedTable(category: string, courses: Course[]): string {
    return (
      /* html */`
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
          ${courses.map(course => this.#buildCourseRow(course)).join('\n')}
        </table>
      </div>
      `
    );
  };
  build(): this {
    const categorizedTables = this.props.__CATEGORIZED_PRE_COURSES.map(({ category, courses }) => {
      const fullCourses = courses.map((course) => ({
        ...course,
        ...this.props.__FETCHED_COURSES[course.code],
      }));
      return this.#buildCategorizedTable(category, fullCourses)
    });
    this.innerHTML = categorizedTables.join('\n');
    return this;
  }
  #attachCellEvent(cell: Element): void {
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
      const setToggleContent = () =>  {
        toggle.innerHTML = isDescriptionActive ? '➖' : '➕';
      };
      const timeout = +isDescriptionActive || 1000;
      setTimeout(setToggleContent, timeout);
    };
  }
  attachEvent(): this {
    const courseContentCells = this.fragment.querySelectorAll('td.course-content');
    if (!courseContentCells || !courseContentCells.length) {
      throw new Error('[ERROR]: No course titles can be found!');
    }
    courseContentCells.forEach(cell => this.#attachCellEvent(cell));
    return this;
  }
}
