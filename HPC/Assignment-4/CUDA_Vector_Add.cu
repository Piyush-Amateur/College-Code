#include <iostream>
#include <cuda_runtime.h>

// Kernel function to add two vectors
__global__ void vectorAdd(int *A, int *B, int *C, int size) {
    int index = threadIdx.x + blockIdx.x * blockDim.x;
    if (index < size) {
        C[index] = A[index] + B[index];
    }
}

int main() {
    const int SIZE = 1000000; // Size of the vectors
    int *A, *B, *C;
    int *d_A, *d_B, *d_C;
    size_t bytes = SIZE * sizeof(int);

    // Allocate host memory
    A = (int*)malloc(bytes);
    B = (int*)malloc(bytes);
    C = (int*)malloc(bytes);

    // Initialize vectors
    for (int i = 0; i < SIZE; ++i) {
        A[i] = i;
        B[i] = i * 2;
    }

    // Allocate device memory
    cudaMalloc(&d_A, bytes);
    cudaMalloc(&d_B, bytes);
    cudaMalloc(&d_C, bytes);

    // Copy data from host to device
    cudaMemcpy(d_A, A, bytes, cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, B, bytes, cudaMemcpyHostToDevice);

    // Launch kernel to add vectors
    int blockSize = 256;
    int gridSize = (SIZE + blockSize - 1) / blockSize;
    vectorAdd<<<gridSize, blockSize>>>(d_A, d_B, d_C, SIZE);

    // Copy result from device to host
    cudaMemcpy(C, d_C, bytes, cudaMemcpyDeviceToHost);

    // Check the result
    for (int i = 0; i < 10; ++i) {
        std::cout << "C[" << i << "] = " << C[i] << std::endl;
    }

    // Free device memory
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

    // Free host memory
    free(A);
    free(B);
    free(C);

    return 0;
}
