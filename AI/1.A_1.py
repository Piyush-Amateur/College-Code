from collections import defaultdict, deque

def add_edge(graph, node1, node2):
    """Add an undirected edge to the graph."""
    graph[node1].append(node2)
    graph[node2].append(node1)

def dfs(graph, node, visited):
    """
    Recursive DFS function.
    
    Args:
    - graph: Dictionary representing adjacency list of the graph.
    - node: Current node being visited.
    - visited: Set of nodes that have been visited.
    """
    # Mark the current node as visited and print it
    visited.add(node)
    print(node, end=" ")

    # Recur for all the vertices adjacent to this vertex
    for neighbor in graph[node]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited)

def bfs_recursive(queue, visited, graph):
    """
    A recursive helper function for BFS.

    Args:
    - queue: A deque containing nodes for BFS.
    - visited: Set of visited nodes.
    - graph: Dictionary representing adjacency list of the graph.
    """
    if not queue:
        return

    node = queue.popleft()
    print(node, end=" ")

    # Enqueue all adjacent nodes that are not visited
    for neighbor in graph[node]:
        if neighbor not in visited:
            visited.add(neighbor)
            queue.append(neighbor)

    # Recursive call
    bfs_recursive(queue, visited, graph)

def main():
    graph = defaultdict(list)
    number_of_edges = int(input("Enter the number of edges: "))
    print("Enter edges in the format Node1 Node2")

    for _ in range(number_of_edges):
        node1, node2 = input().split()
        add_edge(graph, node1, node2)

    start_node = input("Enter the start node for traversal: ")

    # Prepare for DFS
    print("DFS Traversal:")
    visited = set()
    dfs(graph, start_node, visited)

    # Prepare for BFS
    print("\nBFS Traversal:")
    visited = set([start_node])
    queue = deque([start_node])
    bfs_recursive(queue, visited, graph)

if __name__ == "__main__":
    main()
