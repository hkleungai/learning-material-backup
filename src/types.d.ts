interface Course {
  code: string;
  title: string;
  semesters: string[];
}

interface CategorizedCourses {
  [category: string]: Course[];
}
