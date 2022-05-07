if (typeof jQuery != 'undefined') {
    // Schedule for Spring 2022
    const schedule = {
        "L1": [2, 4], 
        "L2": [3, 5], 
        "L3": [3, 5], 
        "L4": [2, 4], 
        "L5": [2, 4], 
    };
    
    $("schedule").each(function(i) {
        const parseAttr = function(attr, useDate) {
            let list = []
            if (attr) {
                for (let value of attr.split(",")) {
                    value = value.split(":");
                    if (useDate) value[0] = new Date(value[0].trim());
                    if (value.length == 1)
                        list.push(value[0]);
                    else
                        list.push([value[0], value[1].split("|")]);
                }
            }
            return list;
        }
        const isHoliday = function(date, section) {
            for (const value of holidays) {
                if (Array.isArray(value)) {
                    if (date.getTime() == value[0].getTime() &&
                        (value[1].includes("all") ||
                         value[1].includes(section))) return true;
                }
                else
                    if (date.getTime() == value.getTime()) return true;
            }

            return false;
        };
        const isCancelled = function(date, section) {
            for (const value of cancelled) {
                if (Array.isArray(value)) {
                    if (date.getTime() == value[0].getTime() &&
                        (value[1].includes("all") ||
                         value[1].includes(section))) return true;
                }
                else
                    if (date.getTime() == value.getTime()) return true;
            }

            return false;
        };
        const getMore = function(section) {
            for (const value of show_more) {
                if (Array.isArray(value)) {
                    if (value[1].includes("all") ||
                        value[1].includes(section)) return value[0];
                }
            }

            return false;
        };

        const start = new Date($(this).attr("start"));
        const end = new Date($(this).attr("end"));
        let lab_info = { "Labs": { "start": start, "end": end } };
        if ($(this).attr("lab-label")) {
            lab_info = {};
            labels = $(this).attr("lab-label");
            labels = labels.split(",");
            for (let label of labels) {
                lab_info[label] = { "start": start, "end": end };
            }
        }
        if ($(this).attr("lab-start")) {
            starts = $(this).attr("lab-start");
            starts = starts.split(",");
            for (let start of starts) {
                start = start.split(":");
                if (start.length == 1)
                    lab_info["Labs"]["start"] = new Date(start[0]);
                else
                    lab_info[start[0]]["start"] = new Date(start[1]);
            }
        }
        if ($(this).attr("lab-end")) {
            ends = $(this).attr("lab-end");
            ends = ends.split(",");
            for (let end of ends) {
                end = end.split(":");
                if (end.length == 1)
                    lab_info["Labs"]["end"] = new Date(end[0]);
                else
                    lab_info[end[0]]["end"] = new Date(end[1]);
            }
        }
        const holidays = parseAttr($(this).attr("holidays"), true);
        const cancelled = parseAttr($(this).attr("cancelled"), true);
        const show_more = parseAttr($(this).attr("show-more"));
        const labs = $(this).attr("labs");
        const options = { month: 'short', day: 'numeric' };
        const is_video_lecture = $(this).attr("video-lecture");

        // Add table
        const table = $("<table class='schedule'></table>");

        // Add lectures
        $.each(schedule, function(section, days) {
            const tr = $("<tr></tr>");
            const th = $("<th><span class='" + section + "'>" + section + "</span>:</th>");
            const this_date = new Date(start);
            const dates = []
            while (this_date.getTime() <= end.getTime()) {
                if (days.indexOf(this_date.getDay()) >= 0 && !isHoliday(this_date, section)) {
                    const date_string = this_date.toLocaleDateString("en-GB", options);

                    if (isCancelled(this_date, section))
                        dates.push("<del>" + date_string + "</del>");
                    else
                        dates.push(date_string);
                }
                this_date.setDate(this_date.getDate() + 1);
            }
            if ((target = getMore(section)) !== false)
                dates.push("<a href='#" + target + "' class='show-more'>more...</a>");

            // hardcode attribute for video lecture
            if (is_video_lecture)
                var td = $("<td>Video lecture</td>");
            else if (dates.length == 0)
                var td = $("<td>No lectures</td>");
            else if ((target = getMore(section)) !== false)
                var td = $("<td>" + dates.join(", ") + "</td>");
            else
                var td = $("<td>" + dates.join(" &amp; ") + "</td>");

            tr.append(th);
            tr.append(td);
            table.append(tr);
        });

        // Add labs
        const tr = $("<tr></tr>");
        if (labs == "yes") {
            for (let label in lab_info) {
                const tr = $("<tr></tr>");

                const lab = lab_info[label];
                const start_date = lab["start"].toLocaleDateString("en-GB", options);
                const end_date = lab["end"].toLocaleDateString("en-GB", options);
                const th = $("<th>" + label + ":</th>");
                const td = $("<td>" + start_date + " - " + end_date + "</td>");
                tr.append(th);
                tr.append(td);

                table.append(tr);
            }
        }
        else {
            const tr = $("<tr></tr>");
            tr.append($("<th>Labs:</th><td>No labs</td>"));
            table.append(tr);
        }

        // Create button link
        const button = $("<a class='d-block w-100 pb-2 text-center small' role='button' href='#' data-toggle='collapse' data-target='#schedule" + i + "'>Click here for<br>lecture and lab dates</a>");
        $(this).append(button);

        // Create collapsible div
        const div = $("<div id='schedule" + i + "' class='collapse'></div>");
        div.append(table);
        $(this).append(div);
    });

    $(".show-more").on("click", function(e) {
        var href = $(this).attr("href");
        var hash = href.substr(href.indexOf("#") + 1);
        if ($("." + hash + " span"))
            $("." + hash + " span").addClass("highlight");
        else
            $("." + hash).addClass("highlight");
        e.preventDefault();
        e.stopPropagation();
    });

}
