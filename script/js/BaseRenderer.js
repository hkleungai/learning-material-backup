var __classPrivateFieldGet = (this && this.__classPrivateFieldGet) || function (receiver, state, kind, f) {
    if (kind === "a" && !f) throw new TypeError("Private accessor was defined without a getter");
    if (typeof state === "function" ? receiver !== state || !f : !state.has(receiver)) throw new TypeError("Cannot read private member from an object whose class did not declare it");
    return kind === "m" ? f : kind === "a" ? f.call(receiver) : f ? f.value : state.get(receiver);
};
var __classPrivateFieldSet = (this && this.__classPrivateFieldSet) || function (receiver, state, value, kind, f) {
    if (kind === "m") throw new TypeError("Private method is not writable");
    if (kind === "a" && !f) throw new TypeError("Private accessor was defined without a setter");
    if (typeof state === "function" ? receiver !== state || !f : !state.has(receiver)) throw new TypeError("Cannot write private member to an object whose class did not declare it");
    return (kind === "a" ? f.call(receiver, value) : f ? f.value = value : state.set(receiver, value)), value;
};
var _BaseRenderer_instances, _BaseRenderer__isPropsSet, _BaseRenderer_isPropsSet_get, _BaseRenderer_isPropsSet_set, _BaseRenderer__props, _BaseRenderer_innerHTML, _BaseRenderer_fragment;
export default class BaseRenderer {
    constructor(props) {
        _BaseRenderer_instances.add(this);
        _BaseRenderer__isPropsSet.set(this, false);
        _BaseRenderer__props.set(this, {});
        _BaseRenderer_innerHTML.set(this, void 0);
        _BaseRenderer_fragment.set(this, void 0);
        this.props = props;
        Object.freeze(this.props);
    }
    render() {
        return this.build().makeFragment().attachEvent();
    }
    makeFragment() {
        if (!__classPrivateFieldGet(this, _BaseRenderer_innerHTML, "f") || !__classPrivateFieldGet(this, _BaseRenderer_innerHTML, "f").length) {
            throw new Error('[ERROR]: Nullish `_innerHTML` is detected! Please implement `build()` properly.');
        }
        const template = document.createElement('template');
        template.innerHTML = __classPrivateFieldGet(this, _BaseRenderer_innerHTML, "f");
        this.fragment = template.content;
        return this;
    }
    get props() {
        return __classPrivateFieldGet(this, _BaseRenderer__props, "f");
    }
    set props(val) {
        if (__classPrivateFieldGet(this, _BaseRenderer_instances, "a", _BaseRenderer_isPropsSet_get)) {
            throw new Error('[ALERT]: DO NOT DIRECTLY MUTATE `props` OUTSIDE BASE CLASS CONSTRUCTOR!!');
        }
        __classPrivateFieldSet(this, _BaseRenderer_instances, true, "a", _BaseRenderer_isPropsSet_set);
        __classPrivateFieldSet(this, _BaseRenderer__props, val, "f");
    }
    get innerHTML() {
        return __classPrivateFieldGet(this, _BaseRenderer_innerHTML, "f");
    }
    set innerHTML(val) {
        if (!val || !val.length) {
            throw new Error('[ERROR]: Nullish `_innerHTML` is detected! Please implement `build()` properly.');
        }
        __classPrivateFieldSet(this, _BaseRenderer_innerHTML, val, "f");
    }
    get fragment() {
        return __classPrivateFieldGet(this, _BaseRenderer_fragment, "f");
    }
    set fragment(val) {
        if (!val || !val.childElementCount) {
            throw new Error('[ERROR]: Empty fragment is detected! Please implement makeFragment() properly.');
        }
        __classPrivateFieldSet(this, _BaseRenderer_fragment, val, "f");
    }
}
_BaseRenderer__isPropsSet = new WeakMap(), _BaseRenderer__props = new WeakMap(), _BaseRenderer_innerHTML = new WeakMap(), _BaseRenderer_fragment = new WeakMap(), _BaseRenderer_instances = new WeakSet(), _BaseRenderer_isPropsSet_get = function _BaseRenderer_isPropsSet_get() {
    return __classPrivateFieldGet(this, _BaseRenderer__isPropsSet, "f");
}, _BaseRenderer_isPropsSet_set = function _BaseRenderer_isPropsSet_set(val) {
    if (!val) {
        throw new Error('[ALERT]: DO NOT MUTATE `props` VIA GUARD VARIABLE!!');
    }
    __classPrivateFieldSet(this, _BaseRenderer__isPropsSet, true, "f");
};
