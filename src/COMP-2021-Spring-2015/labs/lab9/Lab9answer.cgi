#!/usr/local/bin/perl
use CGI qw(:standard);

open(DATA, "data.txt");

while (<DATA>) {
	chomp;
	($name, $id) = split/,/;
	$student{$id} = $name;
}

print header;
print start_html("Student Information");
print h1("Student Information");
print start_form;
print p("Sort Order",
	popup_menu("sort", ["Name", "ID"]),
	submit("Sort"));
print end_form;
print hr;
print "<table border='1'>\n";
print "<tr><td>Name</td><td>ID</td></tr>\n";

if (!param()) {
	foreach $id (keys %student) {
		print "<tr><td>$student{$id}</td><td>$id</td></tr>\n";
	}
} else {
	if (param("sort") eq "Name") {
		%studentrev = reverse %student;
		foreach $name (sort keys %studentrev) {
			print "<tr><td>$name</td><td>$studentrev{$name}</td></tr>\n";
		}
	} else {
		foreach $id (sort keys %student) {
			print "<tr><td>$student{$id}</td><td>$id</td></tr>\n";
		}
	}
}
	print "</table>\n";

	print end_html;
