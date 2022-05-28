import BaseRenderer from 'https:/hkleungai.github.io/mini-web-component/BaseRenderer.js';
export class TagRenderer extends BaseRenderer {
    constructor() {
        super('Tag');
    }
    build() {
        const stringifiedProps = (Object.entries(this.props)
            .filter(([key]) => !['tag', 'children'].includes(key))
            .map(([key, val]) => `${key}="${val}"`)
            .join(' '));
        this.innerHTML = (`
      <${this.props.tag} ${stringifiedProps}></${this.props.tag}>
      `);
        return this;
    }
    makeFragment() {
        if (!this.props.class) {
            return super.makeFragment();
        }
        const template = document.createElement('template');
        template.innerHTML = this.innerHTML;
        const element = template.content.querySelector(`.${this.props.class}`);
        if (!element) {
            throw new Error('[ERROR]: Children tag build fails!');
        }
        if (typeof this.props.children === 'string') {
            element.innerHTML = this.props.children;
            this.fragment = template.content;
            return this;
        }
        this.props.children.forEach(child => {
            if (child instanceof DocumentFragment) {
                element.appendChild(child);
            }
            else {
                element.innerHTML += child;
            }
        });
        this.fragment = template.content;
        return this;
    }
    attachEvent() { return this; }
}
export default new TagRenderer();
