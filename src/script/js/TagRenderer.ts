import BaseRenderer, { BaseProps } from 'https://hkleungai.github.io/mini-web-component/BaseRenderer.js';

export interface ChildrenProps extends BaseProps {
  children: (DocumentFragment | string)[] | string;
}

export interface LinkTagProps extends ChildrenProps, Partial<Omit<HTMLLinkElement, 'children'>> {
  tag: 'link';
}
export interface BaseTagProps extends ChildrenProps, Partial<Omit<HTMLElement, 'children'>> {
  tag: string;
  class: string;
}

export class TagRenderer<T extends (LinkTagProps | BaseTagProps)> extends BaseRenderer<T> {
  constructor() {
    super('Tag');
  }
  protected build(): this {
    const stringifiedProps = (
      Object.entries(this.props)
        .filter(([key]) => !['tag', 'children'].includes(key))
        .map(([key, val]) => `${key}="${val}"`)
        .join(' ')
    );
    this.innerHTML = (
      /* html */`
      <${this.props.tag} ${stringifiedProps}></${this.props.tag}>
      `
    );
    return this;
  }
  protected makeFragment(): this {
    if (!(this.props as BaseTagProps).class) {
      return super.makeFragment();
    }
    const template = document.createElement('template');
    template.innerHTML = this.innerHTML;
    const element = template.content.querySelector(`.${(this.props as BaseTagProps).class}`);
    if (!element) {
      throw new Error('[ERROR]: Children tag build fails!')
    }
    if (typeof this.props.children === 'string') {
      element.innerHTML = this.props.children;
      this.fragment = template.content;
      return this;
    }
    this.props.children.forEach(child => {
      if (child instanceof DocumentFragment) {
        element.appendChild(child)
      }
      else {
        element.innerHTML += child;
      }
    });
    this.fragment = template.content;
    return this;
  }
  protected attachEvent(): this { return this; }
}

export default new TagRenderer();
