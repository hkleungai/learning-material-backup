#include <stdio.h>
#include <cuda_runtime.h>

#define MATRIX_SIZE 64

__global__ void Square(int *A)
{
	// Block index
	/************Add your code***********/

	// Thread index
	/************Add your code***********/

	//Calculation
	/************Add your code***********/
	


}

int main()
{
	int size = MATRIX_SIZE*MATRIX_SIZE*sizeof(int);
	int *h_A = (int *)malloc(size);
	int *d_A;
	int i;

	//Intialize A
	for(i=0;i<MATRIX_SIZE*MATRIX_SIZE;i++)
	{
	                h_A[i] = 2;
	}

	//Allocate the memory in GPU to store the content of A
	/************Add your code***********/

	//Copy h_A to d_A
	/************Add your code***********/
	
	//Allocate blocks and 32*32 threads per block.
	/************Add your code***********/

	//Run the kernel
	/************Add your code***********/

	//Copy the result back to CPU
	/************Add your code***********/


	//free GPU memory for d_A
	/************Add your code***********/


	//free Host Memory
	free(h_A);

	return 0;
}
