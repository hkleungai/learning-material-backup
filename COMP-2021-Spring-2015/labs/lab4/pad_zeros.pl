#!/usr/local/bin/perl5 -w

$TotalDigits = $ARGV[0];

while (<STDIN>)
{	
	$Line = $_;
	chomp($Line);
	if ($Line)
	{
		$NoDigit = length($_);
		$ZerosPad = $TotalDigits - $NoDigit + 1;
		if ($ZerosPad < 0)
		{
			$ZerosPad = 0;
		} 
		print "0" x $ZerosPad . "$Line" . "\n";
	}
	else
	{
		print "*" x $TotalDigits . "\n";
	}
}


