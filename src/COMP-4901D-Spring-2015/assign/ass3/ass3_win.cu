/* 
   skeleton code for assignment3 COMP4901D
   Hash Join
   xjia@ust.hk 2015/04/15
 */
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <thrust/sort.h>
#include <thrust/device_vector.h>
using namespace std;

const int numBits = 6;
const int totalBits = 19;
const int numPart = 1 << numBits;
const int numPerPart = 1 << (totalBits - numBits);
const int mask = (1 << numBits) - 1;
const int numThreads = 128;
const int numBlocks = 512;

/*
   return the partition ID of the input element
*/
  __device__
int getPartID(int element)
{
  element >>= (totalBits - numBits);
  return element & mask;
}

/*
	input: d_key[], array size N
	output: d_pixArray[]
	funciton: for input array d_key[] with size N, return the partition ID array d_pixArray[]
*/
  __global__
void mapPart(int d_key[],int d_pidArray[],int N)
{
  int tid = blockIdx.x * blockDim.x + threadIdx.x;
  int threadNumber = blockDim.x * gridDim.x;

  while(tid < N)
  {
	d_pidArray[tid] = getPartID(d_key[tid]);
	tid += threadNumber;
  }
}

/*
   input: d_pidArray[], array size N
   output: d_Hist[] 
   function: calculate the histogram d_Hist[] based on the partition ID array d_pidArray[]
*/
  __global__
void count_Hist(int d_Hist[],int d_pidArray[],int N)
{
  __shared__ int s_Hist[numThreads * numPart];
  int threadId = blockIdx.x * blockDim.x + threadIdx.x;
  int threadNumber = blockDim.x * gridDim.x;
  int offset = threadIdx.x * numPart;

  for(int i = 0; i < numPart; ++i)
	s_Hist[i + offset] = 0;

  for(int i = threadId; i < N; i += threadNumber)
	s_Hist[offset + d_pidArray[i]]++;

  for(int i = 0; i < numPart; ++i)
	d_Hist[i * threadNumber + threadId] = s_Hist[offset + i];
  __syncthreads();
}
/*
	input: d_pidArray[] (partition ID array), d_psSum[] (prefix sum of histogram), array size N
	output: d_loc[] (location array)
	function: for each element, calculate its corresponding location in the result array based on its partition ID and prefix sum of histogram
*/
  __global__
void write_Hist(int d_pidArray[],int d_psSum[],int d_loc[],int N)
{
  __shared__ int s_psSum[numThreads * numPart];
  int threadId = threadIdx.x + blockIdx.x * blockDim.x;
  int threadNumber = gridDim.x * blockDim.x;
  int offset = threadIdx.x * numPart;

  for(int i = 0; i < numPart; ++i)
	s_psSum[i + offset] = d_psSum[threadId + i * threadNumber];

  for(int i = threadId; i < N; i += threadNumber)
  {
	int pid = d_pidArray[i];
	d_loc[i] = s_psSum[pid + offset];
	s_psSum[pid + offset]++;
  }
}

/*
	input: d_psSum[] (prefix sum of histogram), array size N
	output: start position of each partition
	function: for each partition (chunck to be loaded in the join step), calculate its start position in the result array (the first element's position of this partition)
*/
  __global__
void getStartPos(int d_psSum[],int d_startPos[],int N)
{
  int tid = threadIdx.x + blockIdx.x * blockDim.x;
  int threadNumber = gridDim.x * blockDim.x;

  if(tid >= numPart)
	return;
  d_startPos[tid] = d_psSum[tid * threadNumber];
}

/*
    input: d_key[],d_value[],d_loc[],array size []
	output: out_key[],out_value[]
	function: rewrite the (key,value) pair to its corresponding position based on location array d_loc[]
*/
  __global__
void scatter(int d_key[],float d_value[],int out_key[],float out_value[],int d_loc[],int N)
{
  int threadId = threadIdx.x + blockIdx.x * blockDim.x;
  int threadNumber = blockDim.x * gridDim.x;

  while(threadId < N)
  {
	out_key[d_loc[threadId]] = d_key[threadId];
	out_value[d_loc[threadId]] = d_value[threadId];
	threadId += threadNumber;
  }
}

/*
	function: split the (key,value) array with size N, record the start position of each partition at the same time
*/
void split(int *d_key,float *d_value,int *d_startPos,int N)
{
  /* add your code here */
}

/*
	function: perform hash join on two (key,value) arrays 
*/   
  __global__
void join(int d_key1[],float d_value1[],int d_key2[],float d_value2[],int d_startPos1[],int d_startPos2[],int d_result[],int N1,int N2)
{
  /* add your code here */
}

void hashJoin(int *d_key1,float *d_value1,int *d_key2,float *d_value2,int N1,int N2,int *d_result)
{
  int *d_startPos1,*d_startPos2;
  cudaMalloc(&d_startPos1,sizeof(int) * numPart);
  cudaMalloc(&d_startPos2,sizeof(int) * numPart);
  split(d_key1,d_value1,d_startPos1,N1);
  split(d_key2,d_value2,d_startPos2,N2);

  dim3 grid(numPart);
  dim3 block(1024);

  join<<<grid,block>>>(d_key1,d_value1,d_key2,d_value2,d_startPos1,d_startPos2,d_result,N1,N2);
}
int main()
{
  freopen("in.txt","r",stdin);
  int *h_key1, *h_key2, *d_key1, *d_key2;
  float *h_value1, *h_value2, *d_value1, *d_value2;
  int *h_result, *d_result;
  int N1,N2;

  scanf("%d%d",&N1,&N2);

  h_key1 = (int*)malloc(N1 * sizeof(int));
  h_key2 = (int*)malloc(N2 * sizeof(int));
  h_value1 = (float*)malloc(N1 * sizeof(float));
  h_value2 = (float*)malloc(N2 * sizeof(float));
  h_result = (int*)malloc(N1 * sizeof(int));

  cudaMalloc(&d_key1, N1 * sizeof(int));
  cudaMalloc(&d_key2, N2 * sizeof(int));
  cudaMalloc(&d_value1, N1 * sizeof(float));
  cudaMalloc(&d_value2, N2 * sizeof(float));
  cudaMalloc(&d_result, N1 * sizeof(int));

  for(int i = 0; i < N1; ++i)
	scanf("%d%f",&h_key1[i],&h_value1[i]);

  for(int i = 0; i < N2; ++i)
	scanf("%d%f",&h_key2[i],&h_value2[i]);

  memset(h_result,-1,sizeof(int) * N1);
  cudaMemcpy(d_key1,h_key1, sizeof(int) * N1, cudaMemcpyHostToDevice);
  cudaMemcpy(d_result,h_result, sizeof(int) * N1, cudaMemcpyHostToDevice);
  cudaMemcpy(d_key2,h_key2, sizeof(int) * N2, cudaMemcpyHostToDevice);
  cudaMemcpy(d_value1,h_value1, sizeof(float) * N1, cudaMemcpyHostToDevice);
  cudaMemcpy(d_value2,h_value2, sizeof(float) * N2, cudaMemcpyHostToDevice);
  
  hashJoin(d_key1,d_value1,d_key2,d_value2,N1,N2,d_result);

  cudaMemcpy(h_result,d_result,sizeof(int) * N1, cudaMemcpyDeviceToHost);
  cudaMemcpy(h_key1,d_key1,sizeof(int) * N1, cudaMemcpyDeviceToHost);
  cudaMemcpy(h_key2,d_key2,sizeof(int) * N2, cudaMemcpyDeviceToHost);
  cudaMemcpy(h_value1,d_value1,sizeof(float) * N1, cudaMemcpyDeviceToHost);
  cudaMemcpy(h_value2,d_value2,sizeof(float) * N2, cudaMemcpyDeviceToHost);

  int matched = 0;
  freopen("out.txt","w",stdout);
  for(int i = 0;i < N1; ++i)
  {
	if(h_result[i] == -1)
	  continue;
	matched++;
	printf("Key %d\nValue1 %.2f Value2 %.2f\n\n",h_key1[i],h_value1[i],h_value2[h_result[i]]);
  }
  printf("Matched %d\n",matched);
  fclose(stdout);
  freopen("/dev/tty","w",stdout);
  
  free(h_key1);
  free(h_key2);
  free(h_value1);
  free(h_value2);
  free(h_result);

  cudaFree(d_key1);
  cudaFree(d_key2);
  cudaFree(d_value1);
  cudaFree(d_value2);
  cudaFree(d_result);

  cudaDeviceReset();
  return 0;
}

