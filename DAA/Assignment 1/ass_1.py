# Non-recursive Approach

import time

def fibonacci_iterative(n):
    if n <= 1:
        return n
    a, b = 0, 1
    for _ in range(2, n + 1):
        a, b = b, a + b
    return b

# Example usage
n = 30

start_time = time.time()
result = fibonacci_iterative(n)
end_time = time.time()

execution_time = end_time - start_time
print(f"Iterative Fibonacci({n}) = {result}")
print(f"Execution Time: {execution_time:.6f} seconds")




# Recursive Approach

import time

def fibonacci_recursive(n):
    if n <= 1:
        return n
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2)

# Example usage
n = 30

start_time = time.time()
result = fibonacci_recursive(n)
end_time = time.time()

execution_time = end_time - start_time
print(f"Recursive Fibonacci({n}) = {result}")
print(f"Execution Time: {execution_time:.6f} seconds")
