#!/usr/local/bin/perl5 -w
use CGI qw/:standard/;
@advice = (
           'Make sure that your ihome account is ready to run your cgi program.',
           'Your CGI program should be put inside a cgi-bin folder inside the root directory.',
           'Always check your CGI program in command line before uploading it to the web server.',
           'For your CGI program to run,check the permissions beforehand.'
);
print header,
    start_html("Good Advice"),
    h1("Good Advice");
$action = param('action');

if ($action=~/Message (\d+)/) {
    $message_no = $1-1;
    print strong($advice[$message_no]);
}
print start_form;
foreach (1..4) {
    print submit(-name=>'action',-value=>"Message $_");
}

print end_form,end_html;
