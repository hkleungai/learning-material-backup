if (typeof jQuery != 'undefined') {
    $(document).scroll(function() {
        if ($(document).scrollTop() > 0) {
            if (!$("#shortcuts").hasClass("collapsed"))
                $("button#collapse-button").click();
        }
        else {
            if ($("#shortcuts").hasClass("collapsed"))
                $("button#collapse-button").click();
        }
    });
    $("button#collapse-button").click(function() {
        let pos = 0;
        if (!$("#shortcuts").hasClass("collapsed")) {
            pos = 15 - $("#shortcuts").outerWidth();
            $("button#collapse-button").html("&#x25C0;");
        }
        else {
            $("button#collapse-button").html("&#x25B6;");
        }
        $("#shortcuts").animate({right: pos + "px"});
        $("#shortcuts").toggleClass("collapsed");
    });
}
