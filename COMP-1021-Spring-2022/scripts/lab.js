if (typeof jQuery != 'undefined' && typeof hljs != 'undefined') {
    $(document).ready(function()
    {
        $("pre.python").each(function(i, e) {
            e.innerHTML = e.innerHTML.replace(/^\s*/, "");
            e.innerHTML = e.innerHTML.replace(/\s*$/, "");
            e.innerHTML = e.innerHTML.replace(/\n/g, "<br />");
            hljs.highlightBlock(e, '    ', true);
        });
    });
}
