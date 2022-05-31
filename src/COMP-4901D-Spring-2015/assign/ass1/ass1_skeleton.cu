#include <iostream>
#include <cstdio>
#include <cmath>
#include <cuda_runtime.h>
#include <device_launch_parameters.h>
using namespace std;

const int TILE_WIDTH = 1024;
__global__ void equiJoin(int *key1, float *value1, int *key2, float *value2,int N1,int N2,int *result)
{
  /* fill in your code here */
}
__global__ void equiJoinTiled(int *key1, float *value1, int *key2, float *value2,int N1,int N2,int *result)
{
  __shared__ int s_key[TILE_WIDTH];
  /* fill in your code here */
}

int main()
{
  freopen("in.txt","r",stdin);
  int *h_key1, *h_key2, *d_key1, *d_key2;
  float *h_value1, *h_value2, *d_value1, *d_value2;
  int *h_result1, *h_result2, *d_result1, *d_result2;
  int N1,N2;

  scanf("%d%d",&N1,&N2);
  h_key1 = (int*)malloc(N1 * sizeof(int));
  h_key2 = (int*)malloc(N2 * sizeof(int));
  h_value1 = (float*)malloc(N1 * sizeof(float));
  h_value2 = (float*)malloc(N2 * sizeof(float));
  
  h_result1 = (int*)malloc(N1 * sizeof(int));
  h_result2 = (int*)malloc(N1 * sizeof(int));

  cudaMalloc(&d_key1, N1 * sizeof(int));
  cudaMalloc(&d_key2, N2 * sizeof(int));
  cudaMalloc(&d_value1, N1 * sizeof(float));
  cudaMalloc(&d_value2, N2 * sizeof(float));
  cudaMalloc(&d_result1, N1 * sizeof(int));
  cudaMalloc(&d_result2, N1 * sizeof(int));

  for(int i = 0; i < N1; ++i)
	scanf("%d%f",&h_key1[i],&h_value1[i]);

  for(int i = 0; i < N2; ++i)
	scanf("%d%f",&h_key2[i],&h_value2[i]);

  cudaMemcpy(d_key1,h_key1, sizeof(int) * N1, cudaMemcpyHostToDevice);
  cudaMemcpy(d_key2,h_key2, sizeof(int) * N2, cudaMemcpyHostToDevice);
  cudaMemcpy(d_value1,h_value1, sizeof(float) * N1, cudaMemcpyHostToDevice);
  cudaMemcpy(d_value2,h_value2, sizeof(float) * N2, cudaMemcpyHostToDevice);

  dim3 grid1(ceil(double(N1/1024)));
  dim3 block1(1024);

  dim3 grid2(ceil(double(N1/TILE_WIDTH)));
  dim3 block2(TILE_WIDTH);
  
  cudaEvent_t start;
  cudaEvent_t stop;
  cudaEventCreate(&start);
  cudaEventCreate(&stop);

  //test kernel equiJoin
  cudaEventRecord(start,0);
  
  equiJoin<<<grid1,block1>>>(d_key1,d_value1,d_key2,d_value2,N1,N2,d_result1);
  
  cudaEventRecord(stop,0);
  cudaEventSynchronize(stop);
  float ElapsedTime;
  cudaEventElapsedTime(&ElapsedTime,start,stop);
  printf("kernel equiJoin Elapsed Time: %.3lf ms\n",ElapsedTime);

  cudaMemcpy(h_result1,d_result1,sizeof(int) * N1, cudaMemcpyDeviceToHost);

  //test kernel equiJoinTiled
  cudaEventCreate(&start);
  cudaEventCreate(&stop);
  cudaEventRecord(start,0);
 
  equiJoinTiled<<<grid2,block2>>>(d_key1,d_value1,d_key2,d_value2,N1,N2,d_result2);

  cudaEventRecord(stop,0);
  cudaEventSynchronize(stop);
  cudaEventElapsedTime(&ElapsedTime,start,stop);
  printf("kernel equiJoinTiled Elapsed Time: %.3lf ms\n",ElapsedTime);
  
  cudaMemcpy(h_result2,d_result2,sizeof(int) * N1, cudaMemcpyDeviceToHost);

  //check whether h_result1 is same as h_result2
  bool same = true;
  for(int i = 0; i < N1; ++i)
  {
	if(h_result1[i] != h_result2[i])
	{
	  same = false;
	  break;
	}
  }
  if(!same)
  {
	printf("Error!\n");
	return 0;
  }
  int matched = 0;
  freopen("out.txt","w",stdout);
  for(int i = 0;i < N1; ++i)
  {
	if(h_result1[i] == -1)
	  continue;
	matched++;
	printf("Key %d\nValue1 %.2f Value2 %.2f\n\n",h_key1[i],h_value1[i],h_value2[h_result1[i]]);
  }
  printf("Matched %d\n",matched);
  fclose(stdout);
  
  free(h_key1);
  free(h_key2);
  free(h_value1);
  free(h_value2);
  free(h_result1);
  free(h_result2);

  cudaFree(h_key1);
  cudaFree(h_key2);
  cudaFree(h_value1);
  cudaFree(h_value2);
  cudaFree(h_result1);
  cudaFree(h_result2);
  return 0;
}

