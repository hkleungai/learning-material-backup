var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
import mainRenderer from './MainRenderer.js';
import cssScriptRenderer from './CssScriptRender.js';
import { CATEGORIZED_PRE_COURSES, CSS_LINKS, FETCHED_COURSES, GIT_LOGS } from '../data/index.js';
main();
function main() {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            appendCssScripts();
            yield sleep(50);
            appendElements();
        }
        catch (error) {
            alert(error.message);
            throw error;
        }
    });
}
;
function sleep(time) {
    return __awaiter(this, void 0, void 0, function* () {
        return new Promise((resolve) => setTimeout(resolve, time));
    });
}
function appendCssScripts() {
    const head = document.querySelector('head');
    if (!head || !(head instanceof HTMLHeadElement)) {
        throw new Error('[ERROR]: No html head can be found!!');
    }
    const cssScriptProps = { CSS_LINKS };
    const cssScriptFragment = cssScriptRenderer.render(cssScriptProps).fragment;
    head.append(cssScriptFragment);
}
function appendElements() {
    const body = document.querySelector('body');
    if (!body || !(body instanceof HTMLBodyElement)) {
        throw new Error('[ERROR]: No html body can be found!!');
    }
    const mainProps = { GIT_LOGS, FETCHED_COURSES, CATEGORIZED_PRE_COURSES };
    const mainFragment = mainRenderer.render(mainProps).fragment;
    body.append(mainFragment);
}
