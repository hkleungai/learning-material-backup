/** TODO: Change "code" from string into { dept, code }             */
/** TODO: Change "semesters" from string[] into { year, season }    */
/** TODO: Show surprise "sucks" message upon clicking headers       */
/** TODO: Study ts-doc                                              */
/** TODO: Make some ts index.ts                                     */
/** TODO: Move data to proper json                                  */
/** TODO: Study browser / html test tools                           */
/** TODO: Share __temp_commit var among git hooks                   */

import mainRenderer from './MainRenderer';
import cssScriptRenderer from './CssScriptRender';
import {
  CATEGORIZED_PRE_COURSES,
  CSS_LINKS,
  FETCHED_COURSES,
  GIT_LOGS
} from '../data';

main();

async function main() {
  try {
    appendCssScripts();
    // Prevent element renders before css is properly setup
    await sleep(50);
    appendElements();
  }
  catch (error: unknown) {
    alert((error as Error).message);
    throw error;
  }
};

async function sleep(time: number) {
  return new Promise((resolve) => setTimeout(resolve, time));
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
