interface Course {
  code: string;
  description: string;
  title: string;
  semesters: string[];
}

interface CategorizedCourse {
  category: string;
  courses: Course[];
}

interface CategorizedCourses {
  [category: string]: Course[];
}
