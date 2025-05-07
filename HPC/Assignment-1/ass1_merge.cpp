#include <iostream>
#include <vector>
#include <omp.h>
#include <chrono>
#include <cstdlib>
#include <ctime>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void sequentialMergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        sequentialMergeSort(arr, left, mid);
        sequentialMergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

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
    std::srand(std::time(nullptr));
    int n = 100000;
    std::vector<int> arr_seq(n), arr_par(n);

    for (int i = 0; i < n; ++i) {
        int val = std::rand() % n;
        arr_seq[i] = val;
        arr_par[i] = val;
    }

    std::cout << "--- Merge Sort Performance ---" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    sequentialMergeSort(arr_seq, 0, arr_seq.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_seq = end - start;
    std::cout << "Sequential Merge Sort Time: " << time_seq.count() << " seconds\n";

    start = std::chrono::high_resolution_clock::now();
    parallelMergeSort(arr_par, 0, arr_par.size() - 1);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_par = end - start;
    std::cout << "Parallel Merge Sort Time:   " << time_par.count() << " seconds\n";

    return 0;
}
