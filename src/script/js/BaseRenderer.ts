export default abstract class BaseRenderer<Props> {
  /* INTERFACE
   * ----------------------------------------------
   * - build()!           set `innerHTML` and return `this`
   * - makeFragment()?    set `fragment` by `innerHTML`
   * - attachEvent()!     assign window events with `fragment` and return `this`
   * / render()?          The only public method for chaining computation
   *                      Default flow is `this -> build -> makeFragment -> attachEvent`
   */
  protected abstract build(): this;
  protected abstract attachEvent(): this;

  /* DEFAULT IMPLEMENTATION */
  public constructor(props: Props) {
    this.props = props;
    Object.freeze(this.props);
  }
  public render(): this {
    return this.build().makeFragment().attachEvent();
  }
  // Default approach to obtain Document Fragment by innerHTML
  protected makeFragment() {
    if (!this.#innerHTML || !this.#innerHTML.length) {
      throw new Error('[ERROR]: Nullish `_innerHTML` is detected! Please implement `build()` properly.');
    }
    const template = document.createElement('template');
    template.innerHTML = this.#innerHTML;
    this.fragment = template.content;
    return this;
  }

  // Prevent `props` being offset outside base class constructor
  #_isPropsSet: boolean = false;
  get #isPropsSet() {
    return this.#_isPropsSet;
  }
  set #isPropsSet(val: boolean) {
    if (!val) {
      throw new Error('[ALERT]: DO NOT MUTATE `props` VIA GUARD VARIABLE!!');
    }
    this.#_isPropsSet = true;
  }

  #_props: Props = {} as Props;
  protected get props() {
    return this.#_props;
  }
  private set props(val: Props) {
    if (this.#isPropsSet) {
      throw new Error('[ALERT]: DO NOT DIRECTLY MUTATE `props` OUTSIDE BASE CLASS CONSTRUCTOR!!');
    }
    this.#isPropsSet = true;
    this.#_props = val;
  }

  #innerHTML: string;
  public get innerHTML(): string {
    return this.#innerHTML;
  }
  protected set innerHTML(val: string) {
    if (!val || !val.length) {
      throw new Error('[ERROR]: Nullish `_innerHTML` is detected! Please implement `build()` properly.');
    }
    this.#innerHTML = val;
  }

  #fragment: DocumentFragment;
  public get fragment(): DocumentFragment {
    return this.#fragment;
  }
  protected set fragment(val: DocumentFragment) {
    if (!val || !val.childElementCount) {
      throw new Error('[ERROR]: Empty fragment is detected! Please implement makeFragment() properly.')
    }
    this.#fragment = val;
  }
}
