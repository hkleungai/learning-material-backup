#!/usr/local/bin/perl5 -w


# first read the file and store the data in some 2Darrary named dlist


print "The Sudoku you have entered:\n";
while (!display_board(@dlist))
{
        # first implement a loop to ask for inputting the column and row number for the new cell to fill continuously until a correct one is given. Read "Requirements" carefully to determine the loop structure here.

        # then implement a loop asking for correct input of number for the cell

        # update dlist
}

if (check_blocks(@dlist) && check_rows(@dlist) && check_columns(@dlist) )
{
		print "You successfully finished this Sudoku!\n";
}
else 
{
		print "Sorry, the answer is not correct!\n";
}


sub alpha2num
{
	my $alpha = $_[0];
	my $i = 0;
	foreach ('A'..'I') {
		return $i if ($alpha eq $_); 
		$i++;
        }
}

sub check_blocks
{
# return 1 if every block meets the requirement or 0 otherwise
}

sub check_one_block
{
	my @dlist;
	my $column = pop(@_);
	my $row = pop(@_);
	@dlist = @_;
	my @tempmark = (0,0,0,0,0,0,0,0,0);
	$tempmark[$dlist[$row-1][$column-1] - 1] = 1;
	$tempmark[$dlist[$row-1][$column] - 1] = 1;
	$tempmark[$dlist[$row-1][$column+1] - 1] = 1;
	$tempmark[$dlist[$row][$column-1] - 1] = 1;
	$tempmark[$dlist[$row][$column] - 1] = 1;
	$tempmark[$dlist[$row][$column+1] - 1] = 1;
	$tempmark[$dlist[$row+1][$column-1] - 1] = 1;
	$tempmark[$dlist[$row+1][$column] - 1] = 1;
	$tempmark[$dlist[$row+1][$column+1] - 1] = 1;

	@tempmark = sort(@tempmark);
	if ($tempmark[0] == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

sub check_rows
{
# return 1 if every row meets the requirement or 0 otherwise
}

sub check_columns
{
# return 1 if every column meets the requirement or 0 otherwise
}

sub display_board
{
# this subroutine has two big functionalities
# one, it prints the current board
# second, it returns 1 if the board has been all filled, or 0 otherwise
}




