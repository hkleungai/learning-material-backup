// Have to apply makeFragment() but not build()
// so that the attached events defined in children would not be lost.

import BaseRenderer, { BaseProps } from 'https://hkleungai.github.io/mini-web-component/BaseRenderer.js';

import tagRenderer from './TagRenderer';
import tableRenderer from './TableRenderer';
import noticeBoardRenderer from './NoticeBoardRenderer';
import { Categorized, FetchedCourses, PreCourse } from '../interface/types';

interface MainProps extends BaseProps {
  GIT_LOGS: Record<string, string>;
  CATEGORIZED_PRE_COURSES: Categorized<PreCourse>[];
  FETCHED_COURSES: FetchedCourses;
}

class MainRenderer extends BaseRenderer<MainProps> {
  constructor() {
    super('Main');
  }

  protected build(): this { return this; }

  protected makeFragment(): this {
    const props = {
      tag: 'div',
      class: 'main',
      children: [
        this.#makeLoadingFragment(),
        this.#makePageContentFragment(),
      ],
    };
    this.fragment = tagRenderer.render(props).fragment;
    return this;
  }

  #makeLoadingFragment() {
    return (
      /* html */`
      <div class="loading-wrapper">
        <div class="loading"></div>
      </div>
      `
    )
  }

  #makePageContentFragment() {
    const header = (
      /* html */`
      <h2 class="header">
        University is not that bad, right? 💩
      </h2>
      `
    );

    const noticeBoardProps = {
      GIT_LOGS: this.props.GIT_LOGS
    };
    const noticeBoard = noticeBoardRenderer.render(noticeBoardProps).fragment;

    const tableProps = {
      CATEGORIZED_PRE_COURSES: this.props.CATEGORIZED_PRE_COURSES,
      FETCHED_COURSES: this.props.FETCHED_COURSES,
    };
    const table = tableRenderer.render(tableProps).fragment;

    const closingTag = (
      /* html */`
      <h4 class="closing">
        To Be Continued...
      </h4>
      `
    );

    const PageContentProps = {
      tag: 'div',
      class: 'page-content',
      children: [ header, noticeBoard, table, closingTag ]
    }
    return tagRenderer.render(PageContentProps).fragment;
  }

  protected attachEvent(): this {
    setTimeout(() => {
      if (window.location.hash) {
        window.location.href = window.location.href;
      }
    });
    return this;
  }
}

export default new MainRenderer();
