#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

// Structure for an item
struct Item {
    string name;
    double value, weight;

    // Constructor for item
    Item(string name_, double value_, double weight_) : name(name_), value(value_), weight(weight_) {}
};

// Comparison function to sort items by value-to-weight ratio
bool cmp(Item a, Item b) {
    double r1 = a.value / a.weight;
    double r2 = b.value / b.weight;
    return r1 > r2;
}

// Function to solve the fractional knapsack problem
double fractionalKnapsack(vector<Item>& items, double capacity) {
    // Sort items by value-to-weight ratio
    sort(items.begin(), items.end(), cmp);

    double total_value = 0.0;

    for (auto& item : items) {
        if (capacity >= item.weight) {
            capacity -= item.weight;
            total_value += item.value;
        } else {
            total_value += item.value * (capacity / item.weight);
            break;
        }
    }

    return total_value;
}

int main() {
    vector<Item> items = {
        {"Item 1", 60, 10},
        {"Item 2", 100, 20},
        {"Item 3", 120, 30}
    };
    double capacity = 50.0;

    auto start = chrono::high_resolution_clock::now();
    double max_value = fractionalKnapsack(items, capacity);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> execution_time = end - start;

    cout << "Maximum value we can obtain: " << max_value << endl;
    cout << "Execution Time: " << execution_time.count() << " seconds" << endl;

    return 0;
}
