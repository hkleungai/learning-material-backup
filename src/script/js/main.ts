/** TODO: Change "semesters" from string[] into { year, season }    */
/** TODO: Show surprise "sucks" message upon clicking headers       */
/** TODO: Study ts-doc                                              */
/** TODO: Make some ts index.ts                                     */
/** TODO: Move data to proper json                                  */
/** TODO: Study browser / html test tools                           */
/** TODO: Share __temp_commit var among git hooks                   */

import TableRenderer from './TableRenderer';
import NoticeBoardRenderer from './NoticeBoardRenderer';
import { CATEGORIZED_PRE_COURSES, FETCHED_COURSES, GIT_LOGS } from '../data';

main();

function main() {
  try {
    _main();
  }
  catch (error: unknown) {
    alert((error as Error).message);
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
  })
}
