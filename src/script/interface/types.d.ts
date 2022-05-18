export interface PreCourse {
  code: string;
  semesters: string[];
}

export interface Course extends PreCourse {
  description: string;
  title: string;
}

export interface Categorized<T> {
  category: string;
  courses: T[];
}

export interface FetchedCourses {
  [code: Course['code']]: Pick<Course, 'title' | 'description'>
}

export interface GitLogs {
  [date: string]: string;
}

export interface DailyGitLog {
  date: string;
  logs: string[];
}

export interface DailyGitLogEntries {
  [date: DailyGitLog['date']]: DailyGitLog['logs'];
}
