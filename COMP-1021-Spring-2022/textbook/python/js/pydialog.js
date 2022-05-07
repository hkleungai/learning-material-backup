if (typeof jQuery != 'undefined') {
    $(document).ready(function()
    {
        $("#pydialog").dialog({
            autoOpen: false,
            modal: true,
            width: 600, height: 600,
            show: "blind", hide: "blind",
            buttons: {
                Ok: function() {
                    $(this).dialog("close");
                }
            }
        });
        $("#download_link").focus(function() { $(this).blur(); });
    });

    function setupdisplaypane() {
        $(".displaypane a.file").click(function(event)
        {
            event.preventDefault();

            $this = $(this);

            var py = $this.attr("href");
            $("#pydialog").dialog("option", "title", $this.parent().text());
            $("#download_link").attr("href", py);
            $("#source").html("Loading...");
            $("#source").load(py, function(txt, status) {
                if (status == "error") {
                    $("#source").html("Sorry, failed to load the file.");
                }
                else {
                    $("pre.python").each(function(i, e) {
                        e.innerHTML = e.innerHTML.replace(/^\s*/, "");
                        e.innerHTML = e.innerHTML.replace(/\s*$/, "");
                        e.innerHTML = e.innerHTML.replace(/\n/g, "<br />");
                        hljs.highlightBlock(e, '    ', true);
                    });
                }
            });
            $("#pydialog").dialog("open");
        });
    }
}
