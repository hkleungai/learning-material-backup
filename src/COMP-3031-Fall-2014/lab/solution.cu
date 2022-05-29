#include <stdio.h>
#include <cuda_runtime.h>

#define MATRIX_SIZE 64

__global__ void Square(int *A)
{
	// Block index
	/************Add your code***********/
	int bx = blockIdx.x; 
        int by = blockIdx.y; 
	// Thread index
	/************Add your code***********/
	int tx = threadIdx.x; 
        int ty = threadIdx.y;
	//Calculation
	/************Add your code***********/
	int row = 32*by+ty;
	int column = 32*bx+tx;
	int index = MATRIX_SIZE*row+column;

	A[index]=A[index]*A[index];
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
	cudaMalloc((void **)&d_A,size);

	//Copy h_A to d_A
	/************Add your code***********/
	cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);

	//Allocate blocks and 32*32 threads per block.
	/************Add your code***********/
	dim3 dimBlock(32, 32);
        dim3 dimGrid(2,2);	


	//Run the kernel
	/************Add your code***********/
	Square<<<dimGrid,dimBlock>>>(d_A);

	//Copy the result to CPU
	/************Add your code***********/
	cudaMemcpy(h_A, d_A, size, cudaMemcpyDeviceToHost);

	//free GPU memory for d_A
	/************Add your code***********/
	cudaFree(d_A);

	//free Host Memory
	free(h_A);

	return 0;
}
