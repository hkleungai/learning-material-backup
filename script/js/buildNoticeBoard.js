var buildDailyLogs = function (__GIT_LOGS) {
    var logEntries = Object.entries(__GIT_LOGS);
    var dailyLogObject = logEntries.reduce(function (acc, _a) {
        var key = _a[0], rawLog = _a[1];
        var dateString = key.split(' ')[0];
        var log = rawLog.split(/\s+/).slice(1).join(' ');
        var sentenceCasedLog = log[0].toUpperCase() + log.slice(1);
        if (acc[dateString]) {
            acc[dateString].push(sentenceCasedLog);
        }
        else {
            acc[dateString] = [sentenceCasedLog];
        }
        return acc;
    }, {});
    var dailyLogEntries = Object.entries(dailyLogObject);
    var dailyLogList = dailyLogEntries.map(function (_a) {
        var date = _a[0], logs = _a[1];
        return ({ date: date, logs: logs });
    });
    return dailyLogList.sort(function (a, b) { return new Date((b.date)).getTime() - new Date(a.date).getTime(); });
};
var buildLog = function (log) { return (
/* html */ "\n  <div class=\"daily-log\">\n    ".concat(log, "\n  </div>")); };
var buildDailyLogElements = function (_a) {
    var date = _a.date, logs = _a.logs;
    return (
    /* html */ "\n  <div class=\"daily-notice\">\n    <div class=\"date\">\n      ".concat(date, "\n    </div>\n    <div class=\"daily-log-list\">\n      ").concat(logs.map(buildLog).join('\n'), "\n    </div>\n  </div>\n  "));
};
var buildNoticeBoard = function (__GIT_LOGS) { return (
/* html */ "\n  <div class=\"notice-wrapper\">\n    <h3 class=\"common-title\" id=\"Page Updates\">\n      Page Updates\n    </h3>\n    <div class=\"notice-board\">\n      ".concat(buildDailyLogs(__GIT_LOGS).map(buildDailyLogElements).join('\n'), "\n    </div>\n  </div>\n  ")); };
