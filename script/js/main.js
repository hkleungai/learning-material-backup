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
import { CATEGORIZED_PRE_COURSES, FETCHED_COURSES, GIT_LOGS } from '../data/index.js';
main();
function main() {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            appendElements();
        }
        catch (error) {
            alert(error.message);
            throw error;
        }
    });
}
;
function appendElements() {
    const body = document.querySelector('body');
    if (!body || !(body instanceof HTMLBodyElement)) {
        throw new Error('[ERROR]: No html body can be found!!');
    }
    const mainProps = { GIT_LOGS, FETCHED_COURSES, CATEGORIZED_PRE_COURSES };
    const mainFragment = mainRenderer.render(mainProps).fragment;
    body.append(mainFragment);
}
