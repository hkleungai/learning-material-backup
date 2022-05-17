/** TODO: Build by fragment / template so that attach-event need not be done separately */

const makeTemplate = (content: string): DocumentFragment => {
  const template = document.createElement('template');
  template.innerHTML = content;
  if (!template.innerHTML || !template.innerHTML.length) {
    return throwError('No valid elements can be built!!');
  }
  return template.content;
}

const appendElements = () => {
  const mainDivClosingElement = document.querySelector('div.main h4.closing');
  if (!mainDivClosingElement) {
    return throwError('No header can be found on main div!!');
  }
  const noticeBoardFragment = makeTemplate(buildNoticeBoard(GIT_LOGS));
  mainDivClosingElement.before(noticeBoardFragment);

  const tableFragment = makeTemplate(buildTables(CATEGORIZED_PRE_COURSES, FETCHED_COURSES));
  mainDivClosingElement.before(tableFragment);
}
