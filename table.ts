const buildSemesterCell = (code: string, semester: string) => {
  const link = `${code} ${semester}`.replace(/\s/g, '-');
  return (
    /* html */`
    <td class="course-semester">
      <a href="${link}">${semester}</a>
    </td>
    `
  );
};

const buildCourseRow = ({ code, description, semesters, title }: Course): string => {
  const [firstCell, ...extraCells] = semesters.map(semester => buildSemesterCell(code, semester));
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
        rowSpan="${semesters.length}"
      >
        <div class="course-content">
          <div class="course-title">
            <div>${title}</div>
            <div class="course-description-trigger">➕</div>
          </div>
          <div class="course-description">
            ${description}
          </div>
        </div>
      </td>
      ${firstCell}
    </tr>
    `
  );
  const extraRows = extraCells.map(semester => /* html */`<tr>${semester}</tr>`);
  return `${firstRow}\n${extraRows}`
};

const buildCategoryTable = (category: string, courses: Course[]): string => (
  /* html */`
  <div class="main-content">
    <h3 class="category">${category}</h3>
      <table class="course-list">
        <tr>
          <th>Code</th>
          <th>Title / Content</th>
          <th>Semester</th>
        </tr>
        ${courses.map(buildCourseRow).join('\n')}
      </table>
    </h3>
  </div>
  `
);

const buildTable = (categorizedCourses: CategorizedCourse[]) => (
  categorizedCourses
    .map(({ category, courses }) => buildCategoryTable(category, courses))
    .join('\n')
);
