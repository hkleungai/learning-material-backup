const buildDailyLogs = (__GIT_LOGS: GitLogs): DailyGitLog[] => {
  const logEntries = Object.entries(__GIT_LOGS);
  const dailyLogObject = logEntries.reduce<DailyGitLogEntries>((acc, [key, rawLog]) => {
    const dateString = key.split(' ')[0];
    const log = rawLog.split(/\s+/).slice(1).join(' ');
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

const buildLog = (log: string) => (
  /* html */`
  <div class="daily-log">
    ${log}
  </div>`
);

const buildDailyLogElements = ({ date, logs }: DailyGitLog) => (
  /* html */`
  <div class="daily-notice">
    <div class="date">
      ${date}
    </div>
    <div class="daily-log-list">
      ${logs.map(buildLog).join('\n')}
    </div>
  </div>
  `
);

const buildNoticeBoard = (__GIT_LOGS: Record<string, string>) => (
  /* html */`
  <div class="notice-wrapper">
    <h3 class="common-title" id="Page Updates">
      Page Updates
    </h3>
    <div class="notice-board">
      ${buildDailyLogs(__GIT_LOGS).map(buildDailyLogElements).join('\n')}
    </div>
  </div>
  `
);
