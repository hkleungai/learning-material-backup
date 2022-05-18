/* Random number generator.  Written in C.
Generates N random numbers in [0,1].  This program uses
the millisecond field of the system clock as a seed for random.
If we did not use  a seed then the program would return the
same `random' numbers each time it was called.                  */

/* Call with:                        a.out N                    */

#define MAXRAND  2147483647.0
#include <sys/time.h>

main(argc, argv)
        int argc;
        char *argv[];
{ int n,i;
   long random();
   /* system structs used to keep time data */
   struct timeval tp;
   struct timezone tzp;
 
   /* Get time of day and use it as seed for srandom */
   gettimeofday(&tp, &tzp);
   srandom(tp.tv_usec);

   n = atoi(argv[1]);
   for(i=1;i<=n;i++)
     printf("%f\n", random()/MAXRAND);
}
