import { DailyGitLog, DailyGitLogEntries, GitLogs } from '../interface/types';
import BaseRenderer from './BaseRenderer';

interface NoticeBoardRendererProps {
  __GIT_LOGS: GitLogs;
}
export default class NoticeBoardRenderer extends BaseRenderer<NoticeBoardRendererProps> {
  constructor(props: NoticeBoardRendererProps) {
    super(props);
  }
  #buildGitLogs(__GIT_LOGS: GitLogs): DailyGitLog[] {
    const logEntries = Object.entries(__GIT_LOGS);
    const dailyLogObject = logEntries.reduce<DailyGitLogEntries>((acc, [key, rawLog]) => {
      const dateString = key.split(' ')[0];
      // Get rid of conventional commits' prefixes with the form "...: "
      const log = rawLog.replace(/^.*:\s+/, '');
      // An unfortunatate trick for making sentence-case string
      const sentenceCasedLog = log[0].toUpperCase() + log.slice(1);
      if (acc[dateString]) {
        acc[dateString].push(sentenceCasedLog);
      }
      else {
        acc[dateString] = [sentenceCasedLog];
      }
      return acc;
    }, {});
    const dailyLogEntries = Object.entries<DailyGitLog['logs']>(dailyLogObject);
    const dailyLogList = dailyLogEntries.map<DailyGitLog>(([date, logs]) => ({ date, logs }));
    return dailyLogList.sort((a, b) => new Date((b.date)).getTime() - new Date(a.date).getTime());
  }
  #buildLog(log: string): string {
    return (
      /* html */`
      <div class="daily-log">
        ${log}
      </div>`
    );
  }
  #buildDailyLogs({ date, logs }: DailyGitLog): string {
    return (
      /* html */`
      <div class="daily-notice">
        <div class="date">
          ${date}
        </div>
        <div class="daily-log-list">
          ${logs.map((log) => this.#buildLog(log)).join('\n')}
        </div>
      </div>
      `
    )
  };
  build(): this {
    const gitLogs = this.#buildGitLogs(this.props.__GIT_LOGS);
    const dailyLogs = gitLogs.map((gitLog) => this.#buildDailyLogs(gitLog));
    const notices = dailyLogs.join('\n');
    this.innerHTML = (
      /* html */`
      <div class="notice-wrapper">
        <h3 class="common-title" id="Page Updates">
          Page Updates
        </h3>
        <div class="notice-board">
          ${notices}
        </div>
      </div>
      `
    );
    return this;
  }
  attachEvent(): this { return this; }
}
