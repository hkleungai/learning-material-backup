var __classPrivateFieldGet = (this && this.__classPrivateFieldGet) || function (receiver, state, kind, f) {
    if (kind === "a" && !f) throw new TypeError("Private accessor was defined without a getter");
    if (typeof state === "function" ? receiver !== state || !f : !state.has(receiver)) throw new TypeError("Cannot read private member from an object whose class did not declare it");
    return kind === "m" ? f : kind === "a" ? f.call(receiver) : f ? f.value : state.get(receiver);
};
var _NoticeBoardRenderer_instances, _NoticeBoardRenderer_buildGitLogs, _NoticeBoardRenderer_buildLog, _NoticeBoardRenderer_buildDailyLogs;
import BaseRenderer from 'https:/hkleungai.github.io/mini-web-component/BaseRenderer.js';
export class NoticeBoardRenderer extends BaseRenderer {
    constructor() {
        super('NoticeBoard');
        _NoticeBoardRenderer_instances.add(this);
    }
    ;
    build() {
        const gitLogs = __classPrivateFieldGet(this, _NoticeBoardRenderer_instances, "m", _NoticeBoardRenderer_buildGitLogs).call(this, this.props.GIT_LOGS);
        const dailyLogs = gitLogs.map((gitLog) => __classPrivateFieldGet(this, _NoticeBoardRenderer_instances, "m", _NoticeBoardRenderer_buildDailyLogs).call(this, gitLog));
        const notices = dailyLogs.join('\n');
        this.innerHTML = (`
      <div class="notice-wrapper">
        <h3 class="common-title" id="Page Updates">
          Page Updates
        </h3>
        <div class="notice-board">
          ${notices}
        </div>
      </div>
      `);
        return this;
    }
    attachEvent() { return this; }
}
_NoticeBoardRenderer_instances = new WeakSet(), _NoticeBoardRenderer_buildGitLogs = function _NoticeBoardRenderer_buildGitLogs(GIT_LOGS) {
    const logEntries = Object.entries(GIT_LOGS);
    const dailyLogObject = logEntries.reduce((acc, [key, rawLog]) => {
        const dateString = key.split(' ')[0];
        const log = rawLog.replace(/^.*:\s+/, '');
        const sentenceCasedLog = log[0].toUpperCase() + log.slice(1);
        if (acc[dateString]) {
            acc[dateString].push(sentenceCasedLog);
        }
        else {
            acc[dateString] = [sentenceCasedLog];
        }
        return acc;
    }, {});
    const dailyLogEntries = Object.entries(dailyLogObject);
    const dailyLogList = dailyLogEntries.map(([date, logs]) => ({ date, logs }));
    return dailyLogList.sort((a, b) => new Date((b.date)).getTime() - new Date(a.date).getTime());
}, _NoticeBoardRenderer_buildLog = function _NoticeBoardRenderer_buildLog(log) {
    return (`
      <div class="daily-log">
        ${log}
      </div>`);
}, _NoticeBoardRenderer_buildDailyLogs = function _NoticeBoardRenderer_buildDailyLogs({ date, logs }) {
    return (`
      <div class="daily-notice">
        <div class="date">
          ${date}
        </div>
        <div class="daily-log-list">
          ${logs.map((log) => __classPrivateFieldGet(this, _NoticeBoardRenderer_instances, "m", _NoticeBoardRenderer_buildLog).call(this, log)).join('\n')}
        </div>
      </div>
      `);
};
export default new NoticeBoardRenderer();
