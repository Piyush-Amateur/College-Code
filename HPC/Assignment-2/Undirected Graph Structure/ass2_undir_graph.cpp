#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <omp.h>
#include <unordered_set>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Graph {
public:
    int V; // Number of vertices
    vector<vector<int>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Add undirected edge
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Parallel BFS
    void parallelBFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "Parallel BFS Traversal: ";

        auto start_time = high_resolution_clock::now();

        while (!q.empty()) {
            int size = q.size();

            #pragma omp parallel for
            for (int i = 0; i < size; ++i) {
                int current;

                #pragma omp critical
                {
                    current = q.front();
                    q.pop();
                }

                #pragma omp critical
                cout << current << " ";

                for (int neighbor : adj[current]) {
                    if (!visited[neighbor]) {
                        #pragma omp critical
                        {
                            if (!visited[neighbor]) {
                                visited[neighbor] = true;
                                q.push(neighbor);
                            }
                        }
                    }
                }
            }
        }

        auto end_time = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end_time - start_time);
        cout << "\nTime taken for Parallel BFS: " << duration.count() / 1000.0 << " milliseconds" << endl;
    }

    // Parallel DFS using stack
    void parallelDFS(int start) {
        vector<bool> visited(V, false);
        stack<int> st;

        st.push(start);

        cout << "Parallel DFS Traversal: ";

        auto start_time = high_resolution_clock::now();

        while (!st.empty()) {
            int current;

            #pragma omp critical
            {
                current = st.top();
                st.pop();
            }

            if (!visited[current]) {
                #pragma omp critical
                cout << current << " ";

                visited[current] = true;

                #pragma omp parallel for
                for (int i = adj[current].size() - 1; i >= 0; --i) {
                    int neighbor = adj[current][i];
                    if (!visited[neighbor]) {
                        #pragma omp critical
                        st.push(neighbor);
                    }
                }
            }
        }

        auto end_time = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end_time - start_time);
        cout << "\nTime taken for Parallel DFS: " << duration.count() / 1000.0 << " milliseconds" << endl;
    }
};

int main() {
    // Example graph:
    //     0
    //    / \
    //   1   2
    //  /     \
    // 3       4

    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.parallelBFS(0);
    g.parallelDFS(0);

    return 0;
}
