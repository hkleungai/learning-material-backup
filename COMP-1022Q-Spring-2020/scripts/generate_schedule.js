if (typeof jQuery != 'undefined') {
    // Schedule for Spring 2020
    const schedule = {
        "L1": [1, 3],
        "L2": [1, 5],
        "L3": [3, 5],
        "L4": [1, 3],
        "L5": [2, 4]
    };
    
    $("schedule").each(function(i) {
        const isHoliday = function(date) {
            for (const holiday of holidays) {
                if (date.getTime() == holiday.getTime()) return true;
            }

            return false;
        };

        const start = new Date($(this).attr("start"));
        const end = new Date($(this).attr("end"));
        let lab_start = start;
        if ($(this).attr("lab-start"))
            lab_start = new Date($(this).attr("lab-start"));
        let lab_end = end;
        if ($(this).attr("lab-end"))
            lab_end = new Date($(this).attr("lab-end"));
        const holidays = [];
        if ($(this).attr("holidays")) {
            for (const holiday of $(this).attr("holidays").split(",")) {
                holidays.push(new Date(holiday.trim()));
            }
        }
        const labs = $(this).attr("labs");
        const options = { month: 'short', day: 'numeric' };

        // Add table
        const table = $("<table class='schedule'></table>");

        // Add lectures
        $.each(schedule, function(section, days) {
            const tr = $("<tr></tr>");
            const th = $("<th><span class='" + section + "'>" + section + "</span>:</th>");
            const this_date = new Date(start);
            const dates = []
            while (this_date.getTime() <= end.getTime()) {
                if (days.indexOf(this_date.getDay()) >= 0 && !isHoliday(this_date)) {
                    const date_string = this_date.toLocaleDateString("en-GB", options);
                    dates.push(date_string);
                }
                this_date.setDate(this_date.getDate() + 1);
            }
            if (dates.length == 0)
                var td = $("<td>No lectures</td>");
            else
                var td = $("<td>" + dates.join(" &amp; ") + "</td>");

            tr.append(th);
            tr.append(td);
            table.append(tr);
        });

        // Add labs
        const tr = $("<tr></tr>");
        if (labs == "yes") {
            const start_date = lab_start.toLocaleDateString("en-GB", options);
            const end_date = lab_end.toLocaleDateString("en-GB", options);
            const th = $("<th>Labs:</th>");
            const td = $("<td>" + start_date + " - " + end_date + "</td>");
            tr.append(th);
            tr.append(td);
        }
        else
            tr.append($("<th>Labs:</th><td>No labs</td>"));
        table.append(tr);

        $(this).append(table);
    });
}
