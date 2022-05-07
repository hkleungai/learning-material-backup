if (typeof jQuery != 'undefined') {
    $("calendar").each(function(i) {
        const start = new Date($(this).attr("start"));
        const end = new Date($(this).attr("end"));
        const holidays = [];
        if ($(this).attr("holidays")) {
            for (const holiday of $(this).attr("holidays").split(",")) {
                holidays.push(new Date(holiday.trim()));
            }
        }

        const cal_start = new Date(start);
        cal_start.setDate(start.getDate() - start.getDay());
        const cal_end = new Date(end);
        cal_end.setDate(end.getDate() + (6 - end.getDay()));

        // Add table
        const table = $("<table class='calendar'></table>");

        // Add month
        const month_names = [
            "JAN", "FEB", "MAR", "APR", "MAY", "JUN",
            "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"];
        var tr;
        if (cal_start.getMonth() == cal_end.getMonth()) {
            tr = $("<tr><th class='month' colspan='7'>" +
                   month_names[cal_start.getMonth()] +
                   "</th></tr>");
        }
        else {
            tr = $("<tr><th class='month' colspan='7'>" +
                   month_names[cal_start.getMonth()] + "/" +
                   month_names[cal_end.getMonth()] +
                   "</th></tr>");
        }
        table.append(tr);

        // Add weekdays
        tr = $("<tr></tr>");
        $.each(["S", "M", "T", "W", "T", "F", "S"], function(j, day) {
            var th;
            if (j == 0)
                th = "<th class='sunday'>S</th>";
            else
                th = "<th>" + day + "</th>";
            tr.append(th);
        });
        table.append(tr);

        // Add dates
        const this_date = new Date(cal_start);
        tr = $("<tr></tr>");
        while (this_date.getTime() <= cal_end.getTime()) {
            var td = $("<td>" + this_date.getDate() + "</td>");
            if (this_date.getTime() < start.getTime() ||
                this_date.getTime() > end.getTime())
                td.addClass("dim");
            else if (this_date.getDay() == 0)
                td.addClass("sunday");
            for (const holiday of holidays) {
                if (this_date.getTime() == holiday.getTime())
                    td.addClass("holiday");
            }
            tr.append(td);

            if (this_date.getDay() == 6) {
                table.append(tr);
                tr = $("<tr></tr>");
            }

            this_date.setDate(this_date.getDate() + 1);
        }

        $(this).append(table);
    });
}
