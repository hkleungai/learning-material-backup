#include <iostream.h>
#include <cstdlib> //these 2 include statements are required to generate random numbers
#include <ctime>

#define UPPER_BOUND 100
#define LOWER_BOUND 1

int main()
{
  srand(time(0));	// sets the random seed
  int secretNumber;

  secretNumber = (double) rand() / RAND_MAX * (UPPER_BOUND-LOWER_BOUND+1)
    + LOWER_BOUND;  // generate a random number with the seed between
                    // LOWER_BOUND and UPPER_BOUND

  return 0;
}

