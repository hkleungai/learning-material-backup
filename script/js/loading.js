var loading = function () {
    var loadingWrapperDiv = document.querySelector('div.loading-wrapper');
    if (!loadingWrapperDiv || !(loadingWrapperDiv instanceof HTMLDivElement)) {
        return throwError('No loading elements can be found!!');
    }
    loadingWrapperDiv.style.display = 'flex';
    var mainDiv = document.querySelector('div.main');
    if (!mainDiv || !(mainDiv instanceof HTMLDivElement)) {
        return throwError('No loading elements can be found!!');
    }
    setTimeout(function () {
        loadingWrapperDiv.style.display = 'none';
        mainDiv.style.display = 'flex';
    }, 1000);
};
