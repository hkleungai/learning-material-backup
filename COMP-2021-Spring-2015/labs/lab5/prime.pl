#!/usr/bin/perl -w
    $a = $ARGV[0];

    # Put 2 as the first prime so we won't have an empty array
    my @primes = (2);

    MAIN_LOOP: 
    for my $number_to_check (3 .. $a)
    {
        foreach my $p (@primes)
        {
            if ($number_to_check % $p == 0)
            {
               next MAIN_LOOP;
               
            }
        }

        # If we reached this point it means $number_to_check is not
        # divisible by any prime number that came before it.
        push @primes, $number_to_check;
    }

    foreach my $p (@primes)
    {
        print $p, ", ";
    }
    print "\n";
    $n  = @primes;
    print "We found $n prime numbers in total.\n";

