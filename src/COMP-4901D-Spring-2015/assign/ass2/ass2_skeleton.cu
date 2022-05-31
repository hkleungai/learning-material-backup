/* skeleton code for assignment2 COMP4901D
   xjia@ust.hk 2015/03
 */
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <thrust/sort.h>
#include <thrust/device_vector.h>
using namespace std;

const int TILE_WIDTH = 1024;
__global__ void mergeJoin(int *key1, float *value1, int *key2, float *value2,int N1,int N2,int *result)
{
  //chunk of keys in the shared memory
  __shared__ int s_key[TILE_WIDTH];

  //start and end positions of the elements in the matching chunk
  __shared__ int start;
  __shared__ int end;
  
  //add you code here
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


  cudaEvent_t start;
  cudaEvent_t stop;
  cudaEventCreate(&start);
  cudaEventCreate(&stop);
  
  memset(h_result,-1,sizeof(int) * N1);
  cudaMemcpy(d_key1,h_key1, sizeof(int) * N1, cudaMemcpyHostToDevice);
  cudaMemcpy(d_result,h_result, sizeof(int) * N1, cudaMemcpyHostToDevice);
  cudaMemcpy(d_key2,h_key2, sizeof(int) * N2, cudaMemcpyHostToDevice);
  cudaMemcpy(d_value1,h_value1, sizeof(float) * N1, cudaMemcpyHostToDevice);
  cudaMemcpy(d_value2,h_value2, sizeof(float) * N2, cudaMemcpyHostToDevice);

  cudaEventRecord(start,0);

  thrust::device_ptr<int> dev_key1(d_key1);
  thrust::device_ptr<int> dev_key2(d_key2);
  thrust::device_ptr<float> dev_value1(d_value1);
  thrust::device_ptr<float> dev_value2(d_value2);
  thrust::sort_by_key(dev_key1,dev_key1 + N1, dev_value1);
  thrust::sort_by_key(dev_key2,dev_key2 + N2, dev_value2);
  
  cudaEventRecord(stop,0);
  cudaEventSynchronize(stop);
  float ElapsedTime;
  cudaEventElapsedTime(&ElapsedTime,start,stop);
  printf("Sort Elapsed Time: %.3f ms\n",ElapsedTime);

  dim3 grid(ceil(double(N2)/1024));
  dim3 block(1024);


  cudaEventRecord(start,0);
  mergeJoin<<<grid,block>>>(d_key1,d_value1,d_key2,d_value2,N1,N2,d_result);
  cudaEventRecord(stop,0);
  cudaEventSynchronize(stop);
  cudaEventElapsedTime(&ElapsedTime,start,stop);
  printf("kernel mergeJoin Elapsed Time: %.3f ms\n",ElapsedTime);

  cudaMemcpy(h_result,d_result,sizeof(int) * N1, cudaMemcpyDeviceToHost);
  cudaMemcpy(h_key1,d_key1,sizeof(int) * N1, cudaMemcpyDeviceToHost);
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
  return 0;
}

