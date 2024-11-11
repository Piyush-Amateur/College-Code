#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <chrono>
using namespace std;

// A node of the Huffman Tree
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
    
    Node(char character, int frequency) : ch(character), freq(frequency), left(nullptr), right(nullptr) {}
};

// Comparison object for priority queue
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

// Function to generate Huffman Codes from the Huffman Tree
void generateCodes(Node* root, string str, unordered_map<char, string>& codebook) {
    if (root == nullptr)
        return;
    
    if (root->ch != '\0')  // If it's a leaf node
        codebook[root->ch] = str;
    
    generateCodes(root->left, str + "0", codebook);
    generateCodes(root->right, str + "1", codebook);
}

// Huffman encoding function using a greedy strategy
unordered_map<char, string> huffmanEncoding(unordered_map<char, int>& char_freq) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;
    
    // Build the initial heap
    for (auto& pair : char_freq) {
        minHeap.push(new Node(pair.first, pair.second));
    }
    
    // Build the Huffman Tree
    while (minHeap.size() > 1) {
        Node* node1 = minHeap.top();
        minHeap.pop();
        Node* node2 = minHeap.top();
        minHeap.pop();
        
        Node* merged = new Node('\0', node1->freq + node2->freq);
        merged->left = node1;
        merged->right = node2;
        
        minHeap.push(merged);
    }
    
    Node* root = minHeap.top();
    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);
    
    return huffmanCodes;
}

int main() {
    unordered_map<char, int> char_freq = {{'a', 5}, {'b', 9}, {'c', 12}, {'d', 13}, {'e', 16}, {'f', 45}};
    
    auto start = chrono::high_resolution_clock::now();
    unordered_map<char, string> codes = huffmanEncoding(char_freq);
    auto end = chrono::high_resolution_clock::now();
    
    cout << "Huffman Codes:" << endl;
    for (const auto& pair : codes) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    chrono::duration<double> execution_time = end - start;
    cout << "Execution Time: " << execution_time.count() << " seconds" << endl;
    
    return 0;
}
