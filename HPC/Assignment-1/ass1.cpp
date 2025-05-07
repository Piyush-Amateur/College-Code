#include <iostream>
#include <vector>
#include <omp.h>
#include <algorithm>
#include <chrono>
#include <cstdlib> // For rand and srand
#include <ctime>   // For time

// Function to perform sequential Bubble Sort
void sequentialBubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to perform parallel Bubble Sort using OpenMP
void parallelBubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        #pragma omp parallel for shared(arr, swapped)
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

// Function to merge two sorted subarrays
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to perform sequential Merge Sort
void sequentialMergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        sequentialMergeSort(arr, left, mid);
        sequentialMergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Function to perform parallel Merge Sort using OpenMP
void parallelMergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        #pragma omp parallel sections
        {
            #pragma omp section
            parallelMergeSort(arr, left, mid);
            #pragma omp section
            parallelMergeSort(arr, mid + 1, right);
        }
        merge(arr, left, mid, right);
    }
}

int main() {
    // Seed the random number generator
    std::srand(std::time(nullptr));

    // Define the size of the array
    int n = 10000;
    std::vector<int> arr_seq_bubble(n);
    std::vector<int> arr_par_bubble(n);
    std::vector<int> arr_seq_merge(n);
    std::vector<int> arr_par_merge(n);

    // Fill the arrays with random integers
    for (int i = 0; i < n; ++i) {
        int val = std::rand() % n; // Generate numbers between 0 and n-1
        arr_seq_bubble[i] = val;
        arr_par_bubble[i] = val;
        arr_seq_merge[i] = val;
        arr_par_merge[i] = val;
    }

    // --- Bubble Sort Performance Measurement ---
    std::cout << "--- Bubble Sort Performance ---" << std::endl;

    // Sequential Bubble Sort
    auto start_seq_bubble = std::chrono::high_resolution_clock::now();
    sequentialBubbleSort(arr_seq_bubble);
    auto end_seq_bubble = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_seq_bubble = end_seq_bubble - start_seq_bubble;
    std::cout << "Sequential Bubble Sort Time: " << duration_seq_bubble.count() << " seconds" << std::endl;

    // Parallel Bubble Sort
    auto start_par_bubble = std::chrono::high_resolution_clock::now();
    parallelBubbleSort(arr_par_bubble);
    auto end_par_bubble = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_par_bubble = end_par_bubble - start_par_bubble;
    std::cout << "Parallel Bubble Sort Time:   " << duration_par_bubble.count() << " seconds" << std::endl;

    // --- Merge Sort Performance Measurement ---
    std::cout << "\n--- Merge Sort Performance ---" << std::endl;

    // Sequential Merge Sort
    auto start_seq_merge = std::chrono::high_resolution_clock::now();
    sequentialMergeSort(arr_seq_merge, 0, arr_seq_merge.size() - 1);
    auto end_seq_merge = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_seq_merge = end_seq_merge - start_seq_merge;
    std::cout << "Sequential Merge Sort Time: " << duration_seq_merge.count() << " seconds" << std::endl;

    // Parallel Merge Sort
    auto start_par_merge = std::chrono::high_resolution_clock::now();
    parallelMergeSort(arr_par_merge, 0, arr_par_merge.size() - 1);
    auto end_par_merge = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_par_merge = end_par_merge - start_par_merge;
    std::cout << "Parallel Merge Sort Time:   " << duration_par_merge.count() << " seconds" << std::endl;

    return 0;
}