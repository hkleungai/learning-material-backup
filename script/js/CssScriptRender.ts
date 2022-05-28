import BaseRenderer, { BaseProps } from 'https://hkleungai.github.io/mini-web-component/BaseRenderer.js';

interface CssScriptProps extends BaseProps {
  CSS_LINKS: string[];
}

class CssScriptRenderer extends BaseRenderer<CssScriptProps> {
  constructor() {
    super('CssScript');
  }
  #buildScript(link: string): string {
    return /* html */`<link rel="stylesheet" href="script/css/${link}">`;
  }
  protected build(): this {
    this.innerHTML = this.props.CSS_LINKS.map(link => this.#buildScript(link)).join('\n');
    return this;
  }
  protected attachEvent(): this {
    return this;
  }
}

export default new CssScriptRenderer();
