interface Course {
  code: string;
  title: string;
  semester: string;
  link: string;
}

interface CategorizedCourses {
  [category: string]: Course[];
}

const buildCourseRow = ({ code, title, semester, link }: Course): string => (
  /* html */`
  <tr>
    <td style="width: 20%">${code}</td>
    <td>${title}</td>
    <td style="width: 20%"><a href="${link}">${semester}</a></td>
  </tr>
  `
);

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
