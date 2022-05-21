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
  #buildTable(courses: Course[]): string {
    return (
      /* html */`
      <table class="courses">
        <tr>
          <th>Code</th>
          <th>Title / Content</th>
          <th>Semester</th>
        </tr>
        ${courses.map(course => this.#buildCourseRow(course)).join('\n')}
      </table>
      `
    );
  }
  // Directly copy SVG code from Github markdown link.
  // Do not want to waste time on drawing.
  #buildCategory(category: string): string {
    return (
      /* html */`
      <h3 class="common-title" id="${encodeURIComponent(category)}">
        ${category}
        <svg class="common-title-link" viewBox="0 0 16 16" version="1.1" width="16" height="16">
          <path
            fill-rule="evenodd"
            d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z">
          </path>
        </svg>
      </h3>
      `
    );
  }
  #buildTableWithCategory(category: string, courses: Course[]): string {
    return (
      /* html */`
      <div class="category">
        ${this.#buildCategory(category)}
        ${this.#buildTable(courses)}
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
      return this.#buildTableWithCategory(category, fullCourses)
    });
    this.innerHTML = categorizedTables.join('\n');
    return this;
  }

  #attachSingleDescriptionEvent(cell: Element): void {
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
  #attachDescriptionEvent(): void {
    const courseContentCells = this.fragment.querySelectorAll('td.course-content');
    if (!courseContentCells || !courseContentCells.length) {
      throw new Error('[ERROR]: No course titles can be found!');
    }
    courseContentCells.forEach(cell => this.#attachSingleDescriptionEvent(cell));
  }
  #attachSingleCopyLinkEvent(title: Element): void {
    const svgLink = title.querySelector('svg.common-title-link');
    if (!svgLink || !(svgLink instanceof SVGElement)) {
      throw new Error('[ERROR]: No link element can be found!');
    }
    svgLink.onclick = async () => {
      try {
        const linkToBeCopied =`${window.location.href.replace(/\/+$/, '')}/#${title.id}`;
        await navigator.clipboard.writeText(linkToBeCopied);
        alert('[SUCCESS]: Successfully copy the link');
      }
      catch (error) {
        throw new Error((error as Error).message);
      }
    }
  }
  #attachCopyLinkEvent(): void {
    const titles = this.fragment.querySelectorAll('h3.common-title');
    if (!titles || !titles.length) {
      throw new Error('[ERROR]: No course titles can be found!');
    }
    titles.forEach(title => this.#attachSingleCopyLinkEvent(title));
  }
  attachEvent(): this {
    this.#attachDescriptionEvent();
    this.#attachCopyLinkEvent();
    return this;
  }
}
