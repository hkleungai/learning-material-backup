/**
 *  Demo code of Cuda programming lecture
 *  
 *  This programme is a simple implementation of vector addition in CUDA 
 *   Windows Version
 *
 *      hupmscy@HKUST, Nov. 28, 2012
 *      Revised by xjia@HKUST, Feb. 7, 2015
 *
 */


#include <cstdlib>
#include <cstdio>
#include <cuda_runtime.h>
#include <device_launch_parameters.h>

#ifdef WIN32
#include <ctime>
#include <Windows.h>
int gettimeofday(struct timeval *tp, void *tzp)
{
    time_t clock;
    struct tm tm;
    SYSTEMTIME wtm;

    GetLocalTime(&wtm);
    tm.tm_year = wtm.wYear - 1900;
    tm.tm_mon = wtm.wMonth - 1;
    tm.tm_mday = wtm.wDay;
    tm.tm_hour = wtm.wHour;
    tm.tm_min = wtm.wMinute;
    tm.tm_sec = wtm.wSecond;
    tm.tm_isdst = -1;

    clock = mktime(&tm);
    tp->tv_sec = clock;
    tp->tv_usec = wtm.wMilliseconds * 1000;
    return (0);

}
#endif
// Device code
__global__ void VecAdd(int* A, int* B, int* C)
{
    int i = blockDim.x * blockIdx.x + threadIdx.x;
    C[i] = A[i] + B[i];
}

// Host code
int main()
{
    int *h_A, *h_B, *h_C, *d_A, *d_B, *d_C; 
    int N = 33554432;
    size_t size = N * sizeof(int);
   
    int threadsPerBlock = 1024;
    int blocksPerGrid = N / threadsPerBlock;

    //Time measurement
    timeval kernel_start, kernel_end;
    timeval global_start, global_end;
    float kernel_elapsed_time, global_elapsed_time; 
        
    // Allocate host memory
    h_A = (int*)malloc(size);
    h_B = (int*)malloc(size);
    h_C = (int*)malloc(size);
    
    //Initialization
    for (int i = 0; i < N; i++)
    {
        h_A[i] = i;
        h_B[i] = i;
    }
    
    // Allocate device memory
    cudaMalloc((void**)&d_A, size);
    cudaMalloc((void**)&d_B, size);
    cudaMalloc((void**)&d_C, size);
    
    //Start global timer
    gettimeofday(&global_start, NULL);  

    // Copy vectors from host memory to device memory
    cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, h_B, size, cudaMemcpyHostToDevice);

    
    //Start kernel timer
    gettimeofday(&kernel_start, NULL);      
    
    // Invoke kernel
    VecAdd<<<blocksPerGrid, threadsPerBlock>>>(d_A, d_B, d_C);
    
    //Since kernel launch is asynchronized, block the host code until the kernel finishes
    cudaThreadSynchronize();
    
    //End kernel timer  
    gettimeofday(&kernel_end, NULL);
    
        
    // Copy result from device memory to host memory
    // h_C contains the result in host memory
    cudaMemcpy(h_C, d_C, size, cudaMemcpyDeviceToHost);      
   
    //cudaMemcpy is synchronized, no barrier is needed here
    //Stop global timer
    gettimeofday(&global_end, NULL);                        

    //get kernel elapsed time
    kernel_elapsed_time = 1000*(kernel_end.tv_sec - kernel_start.tv_sec) + (float)(kernel_end.tv_usec - kernel_start.tv_usec)/1000;
    //get global elapsed time
    global_elapsed_time = 1000*(global_end.tv_sec - global_start.tv_sec) + (float)(global_end.tv_usec - global_start.tv_usec)/1000;
    
    printf("elapsed time of gpu vector addition(time cost by data transfer between host and device is excluded): %.2f ms\n", kernel_elapsed_time);
    printf("elapsed time of gpu vector addition(time cost by data transfer between host and device is included): %.2f ms\n", global_elapsed_time);

   //Free host memory
   free(h_A);
   free(h_B);
   free(h_C);
   
   //Free device memory
   cudaFree(d_A);
   cudaFree(d_B);
   cudaFree(d_C);

   getchar();
}

