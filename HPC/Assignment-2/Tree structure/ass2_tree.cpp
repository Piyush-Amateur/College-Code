#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <omp.h>
#include <chrono>

using namespace std::chrono;

// Tree Node definition
struct TreeNode {
    int data;
    std::vector<TreeNode*> children;

    TreeNode(int val) : data(val) {}
};

// Utility function to add a child node
void addChild(TreeNode* parent, TreeNode* child) {
    parent->children.push_back(child);
}

// Parallel BFS
void parallelBFS(TreeNode* root) {
    if (!root) return;

    std::queue<TreeNode*> q;
    q.push(root);

    std::cout << "Parallel BFS Traversal: ";

    while (!q.empty()) {
        int size = q.size();

        #pragma omp parallel for
        for (int i = 0; i < size; ++i) {
            TreeNode* current;
            #pragma omp critical
            {
                current = q.front();
                q.pop();
            }

            #pragma omp critical
            std::cout << current->data << " ";

            for (auto child : current->children) {
                #pragma omp critical
                q.push(child);
            }
        }
    }
    std::cout << std::endl;
}

// Parallel DFS
void parallelDFS(TreeNode* root) {
    if (!root) return;

    std::stack<TreeNode*> st;
    st.push(root);

    std::cout << "Parallel DFS Traversal: ";

    while (!st.empty()) {
        TreeNode* current;
        #pragma omp critical
        {
            current = st.top();
            st.pop();
        }

        #pragma omp critical
        std::cout << current->data << " ";

        // Push children in reverse order to maintain left-to-right traversal
        #pragma omp parallel for
        for (int i = current->children.size() - 1; i >= 0; --i) {
            #pragma omp critical
            st.push(current->children[i]);
        }
    }
    std::cout << std::endl;
}

int main() {
    // Sample Tree:
    //         1
    //       / | \
    //      2  3  4
    //     /      \
    //    5        6

    TreeNode* root = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);

    addChild(root, n2);
    addChild(root, n3);
    addChild(root, n4);
    addChild(n2, n5);
    addChild(n4, n6);
 

    // Measure Parallel BFS
    auto start_bfs = high_resolution_clock::now();
    parallelBFS(root);
    auto end_bfs = high_resolution_clock::now();
    duration<double> bfs_time = end_bfs - start_bfs;
    std::cout << "Parallel BFS Time: " << bfs_time.count() << " seconds\n";

    // Measure Parallel DFS
    auto start_dfs = high_resolution_clock::now();
    parallelDFS(root);
    auto end_dfs = high_resolution_clock::now();
    duration<double> dfs_time = end_dfs - start_dfs;
    std::cout << "Parallel DFS Time: " << dfs_time.count() << " seconds\n";


    return 0;
}
