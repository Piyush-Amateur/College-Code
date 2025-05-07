#include <iostream>
#include <vector>
#include <omp.h>
#include <climits>

using namespace std;

int main() {
    vector<int> data = {3, 7, 2, 9, 4, 10, 5, 1, 6, 8};
    int n = data.size();

    int min_val = INT_MAX;
    int max_val = INT_MIN;
    int sum_val = 0;
    double avg_val;

    // Parallel reduction for min
    #pragma omp parallel for reduction(min:min_val)
    for (int i = 0; i < n; ++i) {
        if (data[i] < min_val) {
            min_val = data[i];
        }
    }

    // Parallel reduction for max
    #pragma omp parallel for reduction(max:max_val)
    for (int i = 0; i < n; ++i) {
        if (data[i] > max_val) {
            max_val = data[i];
        }
    }

    // Parallel reduction for sum
    #pragma omp parallel for reduction(+:sum_val)
    for (int i = 0; i < n; ++i) {
        sum_val += data[i];
    }

    // Average is just sum / n
    avg_val = static_cast<double>(sum_val) / n;

    cout << "Parallel Reduction Results:" << endl;
    cout << "Minimum Value : " << min_val << endl;
    cout << "Maximum Value : " << max_val << endl;
    cout << "Sum           : " << sum_val << endl;
    cout << "Average       : " << avg_val << endl;

    return 0;
}
