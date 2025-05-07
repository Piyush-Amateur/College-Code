#include <iostream>
#include <cuda_runtime.h>


using namespace std;

#define BLOCK_SIZE 2

__global__ void gpuMM(float *A, float *B, float *C, int N) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;

    if (row < N && col < N) {
        float sum = 0.f;
        for (int n = 0; n < N; ++n)
            sum += A[row * N + n] * B[n * N + col];
        C[row * N + col] = sum;
    }
}

int main() {
    int N = BLOCK_SIZE * 1;  // You can change multiplier from 1 to 2, 3, etc. for bigger matrices

    cout << "\nExecuting Matrix Multiplication\n";
    cout << "Matrix size: " << N << " x " << N << endl;

    // Host memory allocation
    float *hA = new float[N * N];
    float *hB = new float[N * N];
    float *hC = new float[N * N];

    // Initialize host matrices
    for (int i = 0; i < N * N; ++i) {
        hA[i] = 2.0f;
        hB[i] = 4.0f;
    }

    // Device memory allocation
    float *dA, *dB, *dC;
    size_t size = N * N * sizeof(float);
    cudaMalloc(&dA, size);
    cudaMalloc(&dB, size);
    cudaMalloc(&dC, size);

    // Copy data to device
    cudaMemcpy(dA, hA, size, cudaMemcpyHostToDevice);
    cudaMemcpy(dB, hB, size, cudaMemcpyHostToDevice);

    // Define grid and block dimensions
    dim3 threads(BLOCK_SIZE, BLOCK_SIZE);
    dim3 blocks((N + BLOCK_SIZE - 1) / BLOCK_SIZE, (N + BLOCK_SIZE - 1) / BLOCK_SIZE);

    // Launch kernel
    gpuMM<<<blocks, threads>>>(dA, dB, dC, N);

    // Synchronize to wait for GPU to finish
    cudaDeviceSynchronize();

    // Copy result back to host
    cudaMemcpy(hC, dC, size, cudaMemcpyDeviceToHost);

    // Print input matrices and result
    cout << "\nInput Matrix A:\n";
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col)
            cout << hA[row * N + col] << " ";
        cout << endl;
    }

    cout << "\nInput Matrix B:\n";
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col)
            cout << hB[row * N + col] << " ";
        cout << endl;
    }

    cout << "\nResultant Matrix C = A * B:\n";
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col)
            cout << hC[row * N + col] << " ";
        cout << endl;
    }

    // Free memory
    delete[] hA;
    delete[] hB;
    delete[] hC;
    cudaFree(dA);
    cudaFree(dB);
    cudaFree(dC);

    cout << "\nFinished." << endl;
    return 0;
}
