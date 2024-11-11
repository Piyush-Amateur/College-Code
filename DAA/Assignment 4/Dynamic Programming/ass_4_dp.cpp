#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

// Function to solve the 0-1 Knapsack problem using dynamic programming
int knapsack_dp(vector<int>& values, vector<int>& weights, int capacity) {
    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;

    auto start = chrono::high_resolution_clock::now();
    int max_value = knapsack_dp(values, weights, capacity);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> execution_time = end - start;

    cout << "Maximum value (DP): " << max_value << endl;
    cout << "Execution Time: " << execution_time.count() << " seconds" << endl;

    return 0;
}
