/**
 *	Demo code of Cuda programming lecture
 *	
 *	This programme is a simple implementation of sequuential vector addition
 *
 *		hupmscy@HKUST, Nov. 28, 2012
 *
 */

#include <cstdlib>
#include <cstdio>
#include <sys/time.h>

int main()
{
    int *h_A, *h_B, *h_C;
    int i;	
    int N = 33554432;
    size_t size = N * sizeof(int);	

    //For time measurement 
    timeval start, end;
    float elapsed_time;

    // Allocate input vectors h_A and h_B in host memory
    h_A = (int*)malloc(size);
    h_B = (int*)malloc(size);
    h_C = (int*)malloc(size);
    
    /*initialize h_A and h_B here*/	
    for (i = 0; i < N; i++)	
    {
	    h_A[i] = i;
	    h_B[i] = i;
    }
    //start timer
    gettimeofday(&start, NULL);	
	
    //vector Add	
    for (i = 0; i < N; i++)
	    h_C[i] = h_A[i] + h_B[i];
   
   //stop timer
   gettimeofday(&end, NULL);

   elapsed_time = 1000*(end.tv_sec-start.tv_sec) + (float)(end.tv_usec-start.tv_usec)/1000;
   printf("elapsed time of sequential vector addition: %.2f ms\n", elapsed_time);
   
   //Free host memory
   free(h_A);
   free(h_B);
   free(h_C);
   
   return 0;
}







