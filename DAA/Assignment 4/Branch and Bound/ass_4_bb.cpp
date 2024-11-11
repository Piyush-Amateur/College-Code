#include <iostream>
#include <vector>
#include <queue>
#include <chrono>
using namespace std;

struct Node {
    int level, value, weight;
    double bound;
    Node(int l, int v, int w, double b) : level(l), value(v), weight(w), bound(b) {}
};

struct Compare {
    bool operator()(const Node& a, const Node& b) {
        return a.bound < b.bound;
    }
};

double bound(Node u, int n, int capacity, vector<int>& weights, vector<int>& values) {
    if (u.weight >= capacity)
        return 0;
    
    double profit_bound = u.value;
    int j = u.level + 1;
    int total_weight = u.weight;
    
    while (j < n && total_weight + weights[j] <= capacity) {
        total_weight += weights[j];
        profit_bound += values[j];
        j++;
    }
    
    if (j < n)
        profit_bound += (capacity - total_weight) * (double)values[j] / weights[j];
    
    return profit_bound;
}

int knapsack_bb(vector<int>& values, vector<int>& weights, int capacity) {
    int n = values.size();
    priority_queue<Node, vector<Node>, Compare> pq;
    
    Node u(-1, 0, 0, 0.0);
    pq.push(u);
    
    int max_profit = 0;
    
    while (!pq.empty()) {
        u = pq.top();
        pq.pop();
        
        if (u.level == n - 1)
            continue;
        
        // Correct the undefined reference to `v`
        Node v(u.level + 1, u.value + values[u.level + 1], u.weight + weights[u.level + 1], 0);
        
        if (v.weight <= capacity && v.value > max_profit)
            max_profit = v.value;
        
        v.bound = bound(v, n, capacity, weights, values);
        
        if (v.bound > max_profit)
            pq.push(v);
        
        // Don't take the current item
        v.weight = u.weight;
        v.value = u.value;
        v.bound = bound(v, n, capacity, weights, values);
        
        if (v.bound > max_profit)
            pq.push(v);
    }
    
    return max_profit;
}

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;

    auto start = chrono::high_resolution_clock::now();
    int max_value = knapsack_bb(values, weights, capacity);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> execution_time = end - start;

    cout << "Maximum value (Branch & Bound): " << max_value << endl;
    cout << "Execution Time: " << execution_time.count() << " seconds" << endl;

    return 0;
}
