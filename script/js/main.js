import TableRenderer from './TableRenderer.js';
import NoticeBoardRenderer from './NoticeBoardRenderer.js';
import { CATEGORIZED_PRE_COURSES, FETCHED_COURSES, GIT_LOGS } from '../data/index.js';
main();
function main() {
    try {
        _main();
    }
    catch (error) {
        alert(error.message);
        throw error;
    }
}
function _main() {
    const mainDivClosingElement = document.querySelector('div.main h4.closing');
    if (!mainDivClosingElement) {
        throw new Error('No closing div can be found!!');
    }
    const renderers = [
        new NoticeBoardRenderer({ __GIT_LOGS: GIT_LOGS }),
        new TableRenderer({
            __CATEGORIZED_PRE_COURSES: CATEGORIZED_PRE_COURSES,
            __FETCHED_COURSES: FETCHED_COURSES,
        })
    ];
    renderers.forEach((renderer) => {
        mainDivClosingElement.before(renderer.render().fragment);
    });
}
