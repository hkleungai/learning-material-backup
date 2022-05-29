#!/usr/bin/perl -w

@words = qw(internet unix perl student program);
@guesses=();
$wrong = 0;
$choice = $words[rand @words];
$hangman = "0-|--<<";
@letters = split(//,$choice);
@hangman = split(//,$hangman);
@blankword = (0) x scalar(@letters);
OUTER: 
	while($wrong < @hangman){
		foreach $i (0..$#letters){
			if($blankword[$i]){
				print $blankword[$i];
			}else{
				print"-";
			}
		}
		print "\n";
		if($wrong){
			print @hangman[0..$wrong-1];
		}
		
		print"\n Your Guess:";
		$guess=<STDIN>; chomp $guess;
		foreach(@guesses){
			next OUTER if ($_ eq $guess);
		}
		
		$right = 0;
		for($i = 0; $i < @letters; $i++){
				if($letters[$i] eq $guess){
					$blankword[$i] = $guess;
					$right = 1;
				}
		}
		$wrong++ unless($right);
		
		if(join ('',@blankword) eq $choice){
			print "You got it right!\n";
			exit;
		}
	}
	print "$hangman\n Sorry,the word was $choice.\n";
