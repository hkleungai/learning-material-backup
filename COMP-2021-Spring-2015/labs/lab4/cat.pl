#!/usr/bin/perl -w

$line_count = 0;
while ($line = <STDIN>) {
	$line_count++;
	@words = split(" ",$line);
	$word_count = scalar(@words);
	$cat_count=0;
	$dog_count=0;
	for ( $i=0; $i < $word_count; $i++) {
		if ($words[$i] eq "cat"){
			$cat_count++;
		}
		if ($words[$i] eq "dog"){
			$dog_count++;
		}
	}
	if ($cat_count > $dog_count){
		print "cats win at line ",$line_count,"\n";
	}
}
