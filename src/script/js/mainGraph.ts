import cssScriptRenderer from './CssScriptRender';
import chartRenderer from './ChartRenderer';

main();

async function main() {
  try {
    appendCssScripts();
    // Prevent element renders before css is properly setup
    await sleep(200);
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
  const cssScriptProps = { CSS_LINKS: ['graph.css'] };
  const cssScriptFragment = cssScriptRenderer.render(cssScriptProps).fragment;
  head.append(cssScriptFragment);
}

function appendElements() {
  const body = document.querySelector('body');
  if (!body || !(body instanceof HTMLBodyElement)) {
    throw new Error('[ERROR]: No html body can be found!!');
  }
  body.append(chartRenderer.render({}).fragment);
}
