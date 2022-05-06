interface Course {
  code: string;
  title: string;
  semester: string;
  link: string;
}

interface CategorizedCourses {
  [category: string]: Course[];
}
