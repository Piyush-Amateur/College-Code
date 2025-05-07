#include <iostream>
#include <vector>
#include <omp.h>
#include <chrono>
#include <cstdlib>
#include <ctime>

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
        if (!swapped) break;
    }
}

int main() {
    std::srand(std::time(nullptr));
    int n = 10000;
    std::vector<int> arr_seq(n), arr_par(n);

    for (int i = 0; i < n; ++i) {
        int val = std::rand() % n;
        arr_seq[i] = val;
        arr_par[i] = val;
    }

    std::cout << "--- Bubble Sort Performance ---" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    sequentialBubbleSort(arr_seq);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_seq = end - start;
    std::cout << "Sequential Bubble Sort Time: " << time_seq.count() << " seconds\n";

    start = std::chrono::high_resolution_clock::now();
    parallelBubbleSort(arr_par);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_par = end - start;
    std::cout << "Parallel Bubble Sort Time:   " << time_par.count() << " seconds\n";

    return 0;
}
