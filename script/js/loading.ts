const loading = () => {
  const loadingWrapperDiv = document.querySelector('div.loading-wrapper');
  if (!loadingWrapperDiv || !(loadingWrapperDiv instanceof HTMLDivElement)) {
    return throwError('No loading elements can be found!!');
  }
  loadingWrapperDiv.style.display = 'flex';
  const mainDiv = document.querySelector('div.main');
  if (!mainDiv || !(mainDiv instanceof HTMLDivElement)) {
    return throwError('No loading elements can be found!!');
  }
  setTimeout(
    () => {
      loadingWrapperDiv.style.display = 'none';
      mainDiv.style.display = 'flex';
    },
    1000,
  );
}
