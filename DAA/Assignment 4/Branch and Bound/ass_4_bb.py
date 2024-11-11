import time
import heapq

class Node:
    def __init__(self, level, value, weight, bound):
        self.level = level
        self.value = value
        self.weight = weight
        self.bound = bound
    
    # To make priority queue act as a max-heap
    def __lt__(self, other):
        return self.bound > other.bound

def bound(u, n, capacity, weights, values):
    if u.weight >= capacity:
        return 0
    profit_bound = u.value
    j = u.level + 1
    total_weight = u.weight
    
    while j < n and total_weight + weights[j] <= capacity:
        total_weight += weights[j]
        profit_bound += values[j]
        j += 1
    
    if j < n:
        profit_bound += (capacity - total_weight) * values[j] / weights[j]
    
    return profit_bound

def knapsack_bb(values, weights, capacity):
    n = len(values)
    queue = []
    u = Node(-1, 0, 0, 0)
    v = Node(0, 0, 0, 0)
    
    heapq.heappush(queue, u)
    max_profit = 0
    
    while queue:
        u = heapq.heappop(queue)
        
        if u.level == n - 1:
            continue
        
        v.level = u.level + 1
        
        # Take the current item
        v.weight = u.weight + weights[v.level]
        v.value = u.value + values[v.level]
        
        if v.weight <= capacity and v.value > max_profit:
            max_profit = v.value
        
        v.bound = bound(v, n, capacity, weights, values)
        
        if v.bound > max_profit:
            heapq.heappush(queue, Node(v.level, v.value, v.weight, v.bound))
        
        # Don't take the current item
        v.weight = u.weight
        v.value = u.value
        v.bound = bound(v, n, capacity, weights, values)
        
        if v.bound > max_profit:
            heapq.heappush(queue, Node(v.level, v.value, v.weight, v.bound))
    
    return max_profit

# Example usage
values = [60, 100, 120]
weights = [10, 20, 30]
capacity = 50

start_time = time.time()
max_value = knapsack_bb(values, weights, capacity)
end_time = time.time()

print(f"Maximum value (Branch & Bound): {max_value}")
print(f"Execution Time: {end_time - start_time:.6f} seconds")
