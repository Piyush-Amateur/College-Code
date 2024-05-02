import sys

def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for column in range(vertices)] for row in range(vertices)]

    def print_mst(self, parent):
        print("Edge \tWeight")
        total_weight = 0
        for i in range(1, self.V):
            print(f"{parent[i]} - {i} \t{self.graph[i][parent[i]]}")
            total_weight += self.graph[i][parent[i]]
        print("Total weight of the MST:", total_weight)

    def min_key(self, key, mst_set):
        min_val = sys.maxsize
        min_index = -1
        for v in range(self.V):
            if key[v] < min_val and not mst_set[v]:
                min_val = key[v]
                min_index = v
        return min_index

    def prim_mst(self):
        key = [sys.maxsize] * self.V
        parent = [None] * self.V
        key[0] = 0
        mst_set = [False] * self.V
        parent[0] = -1

        for _ in range(self.V):
            u = self.min_key(key, mst_set)
            mst_set[u] = True
            for v in range(self.V):
                if 0 < self.graph[u][v] < key[v] and not mst_set[v]:
                    key[v] = self.graph[u][v]
                    parent[v] = u

        self.print_mst(parent)

def main():
    print("Select the algorithm:")
    print("1. Selection Sort")
    print("2. Minimum Spanning Tree (Prim's Algorithm)")
    choice = int(input("Enter choice (1-2): "))
    
    if choice == 1:
        arr = list(map(int, input("Enter numbers separated by space: ").split()))
        sorted_arr = selection_sort(arr)
        print("Sorted array:", sorted_arr)
    elif choice == 2:
        vertices = int(input("Enter number of vertices: "))
        edges = int(input("Enter number of edges: "))
        graph = Graph(vertices)
        print("Enter the edges in the format: v1 v2 weight (vertex numbering starts at 0)")
        for _ in range(edges):
            v1, v2, weight = map(int, input().split())
            if v1 >= vertices or v2 >= vertices or v1 < 0 or v2 < 0:
                print("Invalid vertex index. Vertex indices must be between 0 and", vertices-1)
                continue
            graph.graph[v1][v2] = weight
            graph.graph[v2][v1] = weight  # Because it's an undirected graph
        graph.prim_mst()
    else:
        print("Invalid choice")

if __name__ == "__main__":
    main()
