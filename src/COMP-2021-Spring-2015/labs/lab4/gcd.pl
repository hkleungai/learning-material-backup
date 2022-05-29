#!/usr/bin/perl -w

$first = $ARGV[0];
$second = $ARGV[1];

if ($first < $second)
{
	$min = $first;
}
else
{
	$min = $second;
}

for ($i = $min; $i > 1; $i--)
{
	if ($first % $i == 0 && $second % $i == 0)
	{
		print "The gcd of $first and $second is $i\n";
		last;
	}
}


