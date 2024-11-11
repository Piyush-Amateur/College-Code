import time

# Function to solve the fractional knapsack problem
def fractional_knapsack(items, capacity):
    # Sort items by value-to-weight ratio in descending order
    items.sort(key=lambda x: x[1] / x[2], reverse=True)
    
    total_value = 0.0
    for item in items:
        name, value, weight = item
        if capacity - weight >= 0:
            capacity -= weight
            total_value += value
        else:
            fraction = capacity / weight
            total_value += value * fraction
            break

    return total_value

# Example usage
items = [("Item 1", 60, 10), ("Item 2", 100, 20), ("Item 3", 120, 30)]
capacity = 50

start_time = time.time()
max_value = fractional_knapsack(items, capacity)
end_time = time.time()

print(f"Maximum value we can obtain: {max_value}")
print(f"Execution Time: {end_time - start_time:.6f} seconds")
