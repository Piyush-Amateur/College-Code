// Non-recursive Approach

#include <iostream>
#include <chrono>
using namespace std;

int fibonacci_iterative(int n) {
    if (n <= 1)
        return n;
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    int n = 30;

    auto start = chrono::high_resolution_clock::now();
    int result = fibonacci_iterative(n);
    auto stop = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = stop - start;
    
    cout << "Iterative Fibonacci(" << n << ") = " << result << endl;
    cout << "Execution Time: " << duration.count() << " seconds" << endl;

    return 0;
}

// Resursive Approach

/*
// Recursive Approach

#include <iostream>
#include <chrono>
using namespace std;

int fibonacci_recursive(int n) {
    if (n <= 1)
        return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main() {
    int n = 30;

    auto start = chrono::high_resolution_clock::now();
    int result = fibonacci_recursive(n);
    auto stop = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = stop - start;
    
    cout << "Recursive Fibonacci(" << n << ") = " << result << endl;
    cout << "Execution Time: " << duration.count() << " seconds" << endl;

    return 0;
}

*/