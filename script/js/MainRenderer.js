var __classPrivateFieldGet = (this && this.__classPrivateFieldGet) || function (receiver, state, kind, f) {
    if (kind === "a" && !f) throw new TypeError("Private accessor was defined without a getter");
    if (typeof state === "function" ? receiver !== state || !f : !state.has(receiver)) throw new TypeError("Cannot read private member from an object whose class did not declare it");
    return kind === "m" ? f : kind === "a" ? f.call(receiver) : f ? f.value : state.get(receiver);
};
var _MainRenderer_instances, _MainRenderer_makeLoadingFragment, _MainRenderer_makePageContentFragment;
import BaseRenderer from 'https:/hkleungai.github.io/mini-web-component/BaseRenderer.js';
import tagRenderer from './TagRenderer.js';
import tableRenderer from './TableRenderer.js';
import noticeBoardRenderer from './NoticeBoardRenderer.js';
class MainRenderer extends BaseRenderer {
    constructor() {
        super('Main');
        _MainRenderer_instances.add(this);
    }
    build() { return this; }
    makeFragment() {
        const props = {
            tag: 'div',
            class: 'main',
            children: [
                __classPrivateFieldGet(this, _MainRenderer_instances, "m", _MainRenderer_makeLoadingFragment).call(this),
                __classPrivateFieldGet(this, _MainRenderer_instances, "m", _MainRenderer_makePageContentFragment).call(this),
            ],
        };
        this.fragment = tagRenderer.render(props).fragment;
        return this;
    }
    attachEvent() {
        setTimeout(() => {
            if (window.location.hash) {
                window.location.href = window.location.href;
            }
        });
        return this;
    }
}
_MainRenderer_instances = new WeakSet(), _MainRenderer_makeLoadingFragment = function _MainRenderer_makeLoadingFragment() {
    return (`
      <div class="loading-wrapper">
        <div class="loading"></div>
      </div>
      `);
}, _MainRenderer_makePageContentFragment = function _MainRenderer_makePageContentFragment() {
    const header = (`
      <h2 class="header">
        HKUST is not that bad, right? 💩
      </h2>
      `);
    const noticeBoardProps = {
        GIT_LOGS: this.props.GIT_LOGS
    };
    const noticeBoard = noticeBoardRenderer.render(noticeBoardProps).fragment;
    const tableProps = {
        CATEGORIZED_PRE_COURSES: this.props.CATEGORIZED_PRE_COURSES,
        FETCHED_COURSES: this.props.FETCHED_COURSES,
    };
    const table = tableRenderer.render(tableProps).fragment;
    const closingTag = (`
      <h4 class="closing">
        To Be Continued...
      </h4>
      `);
    const PageContentProps = {
        tag: 'div',
        class: 'page-content',
        children: [header, noticeBoard, table, closingTag]
    };
    return tagRenderer.render(PageContentProps).fragment;
};
export default new MainRenderer();
