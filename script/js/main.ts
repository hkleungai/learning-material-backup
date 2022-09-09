/** TODO: Change "code" from string into { dept, code }                 */
/** TODO: Change "semesters" from string[] into { year, season }        */
/** TODO: Show surprise "sucks" message upon clicking headers           */
/** TODO: Study ts-doc                                                  */
/** TODO: Make TagRender take nested json                               */
/** TODO: Make some ts index.ts                                         */
/** TODO: Move data to proper json                                      */
/** TODO: Study browser / html test tools                               */
/** TODO: Share __temp_commit var among git hooks                       */
/** TODO: Make codes more OOP                                           */

import mainRenderer from './MainRenderer';
import {
  CATEGORIZED_PRE_COURSES,
  FETCHED_COURSES,
  GIT_LOGS
} from '../data';

main();

async function main() {
  try {
    appendElements();
  }
  catch (error: unknown) {
    alert((error as Error).message);
    throw error;
  }
};

function appendElements() {
  const body = document.querySelector('body');
  if (!body || !(body instanceof HTMLBodyElement)) {
    throw new Error('[ERROR]: No html body can be found!!');
  }
  const mainProps = { GIT_LOGS, FETCHED_COURSES, CATEGORIZED_PRE_COURSES };
  const mainFragment = mainRenderer.render(mainProps).fragment;
  body.append(mainFragment);
}
