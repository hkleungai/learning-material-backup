var __classPrivateFieldGet = (this && this.__classPrivateFieldGet) || function (receiver, state, kind, f) {
    if (kind === "a" && !f) throw new TypeError("Private accessor was defined without a getter");
    if (typeof state === "function" ? receiver !== state || !f : !state.has(receiver)) throw new TypeError("Cannot read private member from an object whose class did not declare it");
    return kind === "m" ? f : kind === "a" ? f.call(receiver) : f ? f.value : state.get(receiver);
};
var _CssScriptRenderer_instances, _CssScriptRenderer_buildScript;
import BaseRenderer from 'https:/hkleungai.github.io/mini-web-component/BaseRenderer.js';
class CssScriptRenderer extends BaseRenderer {
    constructor() {
        super('CssScript');
        _CssScriptRenderer_instances.add(this);
    }
    build() {
        this.innerHTML = this.props.CSS_LINKS.map(link => __classPrivateFieldGet(this, _CssScriptRenderer_instances, "m", _CssScriptRenderer_buildScript).call(this, link)).join('\n');
        return this;
    }
    attachEvent() {
        return this;
    }
}
_CssScriptRenderer_instances = new WeakSet(), _CssScriptRenderer_buildScript = function _CssScriptRenderer_buildScript(link) {
    return `<link rel="stylesheet" href="script/css/${link}">`;
};
export default new CssScriptRenderer();
