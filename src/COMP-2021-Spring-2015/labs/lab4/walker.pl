#!/usr/bin/perl -w
use Switch;

print "Input an integer size range from 2 on...\n";
chomp($size = <STDIN>);

#randomly drop to a location
$x = int rand ($size + 1); 
$y = int rand ($size + 1);

while (1)
{
	print "Current coordinate: $x, $y \n";
	print "Which direction to go? Enter L for left, R for right, U for up, D for down!\n";
        print "Enter Q if you want to quit!\n";        
	
	chomp($direction = <STDIN>);
	$moved = 0;
	switch($direction)
	{
        case "L"
	{
		if ($x != 1)
		{ $x = $x - 1; $moved = 1;}
	}
	case "R"
	{
		if ($x != $size)
		{ $x = $x + 1; $moved = 1;}
	}
	case "U"
	{
		if ($y != 1)
		{ $y = $y - 1; $moved = 1; }
	}
	case "D"
	{
		if ($y != $size)
		{ $y = $y + 1; $moved = 1; }
	}
	case "Q"
	{
		exit;
	}
	else { print "Input Not Valid!\n"
	         $moved = 1; }
	}

	if ($moved == 0)
	{
		print "Cannot move this way!\n";
	}
}

