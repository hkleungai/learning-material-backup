declare module 'https://hkleungai.github.io/mini-web-component/BaseRenderer.js' {
  export interface BaseProps {
  }
  export default abstract class BaseRenderer<Props extends BaseProps> {
    #private;
    protected abstract build(): this;
    protected abstract attachEvent(): this;
    protected constructor(name: string);
    render(props: Props): this;
    protected makeFragment(): this;
    protected get props(): Props;
    private set props(value);
    get innerHTML(): string;
    protected set innerHTML(val: string);
    get fragment(): DocumentFragment;
    protected set fragment(val: DocumentFragment);
  }
}
