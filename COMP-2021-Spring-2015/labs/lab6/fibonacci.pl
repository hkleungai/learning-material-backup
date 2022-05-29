#!/usr/bin/perl -w

@sampleValues = (0, 1, 2, 3, 4, 5, 6, 10, 20, 30);

foreach ( @sampleValues ) {
	   print "fibonacci( $_ ) = ", fibonacci( $_ ), "\n";
}

sub fibonacci
{
	my $number = shift;
	if ( $number == 0 or $number == 1 ) 
	{  return $number; } 
	else 
	{  return fibonacci( $number - 1 ) + fibonacci( $number - 2 ); }
}



