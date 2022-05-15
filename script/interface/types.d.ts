interface PreCourse {
  code: string;
  semesters: string[];
}

interface Course extends PreCourse {
  description: string;
  title: string;
}

interface Categorized<T> {
  category: string;
  courses: T[];
}

interface FetchedCourses {
  [code: Course['code']]: Pick<Course, 'title' | 'description'>
}

interface GitLogs {
  [date: string]: string;
}

interface DailyGitLog {
  date: string;
  logs: string[];
}

interface DailyGitLogEntries {
  [date: DailyGitLog['date']]: DailyGitLog['logs'];
}
