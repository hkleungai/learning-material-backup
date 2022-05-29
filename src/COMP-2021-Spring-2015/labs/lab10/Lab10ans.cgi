#!/usr/local/bin/perl5 -w
use CGI qw(:standard);
use CGI::Carp qw(warningsToBrowser fatalsToBrowser);
use strict;

my $a = "datafile";  

if (param()){
    open(OUT, ">>$a");     
    my %form;

    foreach my $p (param()) {
        $form{$p} = param($p);
	    if ( $p ne "submit") {
            print OUT "$p = $form{$p}<br>\n";
	    }	
    }
} else { 
    unlink $a; 
}
close(OUT);

print header;
print start_html("Input Information"),
start_form,
"Your name: ",textfield(-name=>'Name'),
"<br/>", 
"Your student ID: ",textfield(-name=>'ID'), 
"<br/>",
submit(-name=>"submit", -value=>'Record'),
end_form;
print "<br/>";
open(IN, "<$a"); 
while(<IN>){
	print $_;
}
close(IN);
print end_html;