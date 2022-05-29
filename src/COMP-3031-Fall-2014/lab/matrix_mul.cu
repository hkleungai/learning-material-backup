#include <stdio.h>
#include <cuda_runtime.h>

#define M_SIZE	   32
#define BLOCK_SIZE 16

//Calculate the multiplication of two 32*32 matrices A and B in gpu and store the result in C.
//Each block calculate 16*16 submaxtrix of C.
__global__ void Mul(int *A,int *B,int *C,int width_A,int width_B)
{
        // Block index
    	int bx = blockIdx.x;
        int by = blockIdx.y;

        // Thread index
        int tx = threadIdx.x;
        int ty = threadIdx.y;

        //Index of the first sub-matrix of A and B processed by the block
        int aBegin=width_A*BLOCK_SIZE*by;
        int bBegin=BLOCK_SIZE*bx;

        //Csub of each thread stores corresponding element of the block sub-matrix.
        int Csub=0;
        int a=aBegin,b=bBegin;

	// Shared memory for the sub-matrix of A
	__shared__ int As[BLOCK_SIZE][BLOCK_SIZE];
	// Shared memory for the sub-matrix of B
	__shared__ int Bs[BLOCK_SIZE][BLOCK_SIZE];

	for (;a<aBegin+width_A-1;a+=BLOCK_SIZE,b+=BLOCK_SIZE*width_B) 
	{
        	// Load the matrices from global memory to shared memory;
        	// each thread loads one element of each matrix
        	As[ty][tx] = A[a+width_A*ty + tx];
        	Bs[ty][tx] = B[b+width_B*ty + tx];

       		// Synchronize to make sure the matrices are loaded
         	__syncthreads();

        	for (int k=0;k<BLOCK_SIZE;k++)
        	Csub+=As[ty][k]*Bs[k][tx];

        	//Make sure computation is done before loading new matrices for global memory.
        	__syncthreads();
	}

	//Write the block sub-matrix to global memory.
	int c=width_B*BLOCK_SIZE*by+BLOCK_SIZE*bx;
	C[c+width_B*ty+tx] = Csub;
}

int main()
{
	int size = M_SIZE*M_SIZE*sizeof(int);
	int *h_A=(int*)malloc(size);
	int *h_B=(int*)malloc(size);
	int *h_C=(int*)malloc(size);

	int *d_A,*d_B,*d_C;
	int i, j;
	//Intialize A,B,C
	for(i=0;i<M_SIZE*M_SIZE;i++)
	{
        	h_A[i]=1;
        	h_B[i]=1;
        	h_C[i]=0;
	}

	//Allocate the memory in GPU to store the content of A,B,C
	cudaMalloc((void **)&d_A, size);
	cudaMalloc((void **)&d_B, size);
	cudaMalloc((void **)&d_C, size);

	//Copy h_A, h_B to d_A,d_B
	cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);
	cudaMemcpy(d_B, h_B, size, cudaMemcpyHostToDevice);

	//Allocate 4 blocks and 256 threads per block.
	dim3 dimBlock(BLOCK_SIZE, BLOCK_SIZE);
	dim3 dimGrid(2,2);
	Mul<<<dimGrid,dimBlock>>>(d_A, d_B, d_C, M_SIZE, M_SIZE);

	cudaMemcpy(h_C, d_C, size, cudaMemcpyDeviceToHost);

	//print the result
	for(i=0; i<M_SIZE; i++)
	{
		for(j=0; j<M_SIZE; j++)
		{
			printf("%d ", h_C[i*M_SIZE+j]);
		}
		printf("\n");
	}
	printf("Press Enter to stop\n");
	getchar();

	cudaFree(d_A);
	cudaFree(d_B);
	cudaFree(d_C);

	free(h_A);
	free(h_B);
	free(h_C);

	return 0;
}

