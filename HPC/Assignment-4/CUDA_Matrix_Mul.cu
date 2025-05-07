#include <iostream>
#include <cuda_runtime.h>

// Kernel function for matrix multiplication
__global__ void matrixMultiply(int *A, int *B, int *C, int N) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    if (row < N && col < N) {
        int value = 0;
        for (int k = 0; k < N; ++k) {
            value += A[row * N + k] * B[k * N + col];
        }
        C[row * N + col] = value;
    }
}

int main() {
    const int N = 1024; // Size of the matrix (N x N)
    size_t bytes = N * N * sizeof(int);
    
    int *A, *B, *C;
    int *d_A, *d_B, *d_C;

    // Allocate host memory
    A = (int*)malloc(bytes);
    B = (int*)malloc(bytes);
    C = (int*)malloc(bytes);

    // Initialize matrices
    for (int i = 0; i < N * N; ++i) {
        A[i] = i % 100;
        B[i] = (i * 2) % 100;
    }

    // Allocate device memory
    cudaMalloc(&d_A, bytes);
    cudaMalloc(&d_B, bytes);
    cudaMalloc(&d_C, bytes);

    // Copy data from host to device
    cudaMemcpy(d_A, A, bytes, cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, B, bytes, cudaMemcpyHostToDevice);

    // Set up execution configuration
    dim3 threadsPerBlock(16, 16);
    dim3 numBlocks((N + 15) / 16, (N + 15) / 16);

    // Launch kernel to multiply matrices
    matrixMultiply<<<numBlocks, threadsPerBlock>>>(d_A, d_B, d_C, N);

    // Copy result from device to host
    cudaMemcpy(C, d_C, bytes, cudaMemcpyDeviceToHost);

    // Check part of the result
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cout << "C[" << i << "][" << j << "] = " << C[i * N + j] << std::endl;
        }
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
