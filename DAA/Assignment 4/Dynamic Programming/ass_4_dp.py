import time

# Function to solve the 0-1 Knapsack problem using dynamic programming
def knapsack_dp(values, weights, capacity):
    n = len(values)
    dp = [[0] * (capacity + 1) for _ in range(n + 1)]
    
    # Build the DP table
    for i in range(1, n + 1):
        for w in range(1, capacity + 1):
            if weights[i - 1] <= w:
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1])
            else:
                dp[i][w] = dp[i - 1][w]
    
    return dp[n][capacity]

# Example usage
values = [60, 100, 120]
weights = [10, 20, 30]
capacity = 50

start_time = time.time()
max_value = knapsack_dp(values, weights, capacity)
end_time = time.time()

print(f"Maximum value (DP): {max_value}")
print(f"Execution Time: {end_time - start_time:.6f} seconds")
