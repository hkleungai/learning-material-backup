const buildSemesterCell = (code: string, semester: string) => {
  const link = `${code} ${semester}`.replace(/\s/g, '-');
  return (
    /* html */`
    <td style="width: 20%">
      <a href="${link}">${semester}</a>
    </td>
    `
  );
}

const buildCourseRow = ({ code, title, semesters }: Course): string => {
  const [firstCell, ...extraCells] = semesters.map(semester => buildSemesterCell(code, semester));
  const firstRow = (
    /* html */`
    <tr>
      <td style="width: 20%" rowSpan="${semesters.length}">${code}</td>
      <td rowSpan="${semesters.length}">${title}</td>
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
          <th>Course Code</th>
          <th>Course Title</th>
          <th>Semester</th>
        </tr>
        ${courses.map(buildCourseRow).join('\n')}
      </table>
    </h3>
  </div>
  `
);

const buildTable = (categorizedCourses: CategorizedCourses) => (
  Object
    .entries(categorizedCourses)
    .map((props) => buildCategoryTable(...props))
    .join('\n')
)
