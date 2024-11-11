import heapq
import time

# Define a node of the Huffman Tree
class Node:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None
    
    # Define comparison operators for priority queue (min-heap)
    def __lt__(self, other):
        return self.freq < other.freq

# Function to generate Huffman codes from the Huffman tree
def generate_codes(node, prefix="", codebook={}):
    if node:
        if node.char is not None:
            codebook[node.char] = prefix
        generate_codes(node.left, prefix + "0", codebook)
        generate_codes(node.right, prefix + "1", codebook)
    return codebook

# Huffman encoding function using a greedy strategy
def huffman_encoding(char_freq):
    heap = [Node(char, freq) for char, freq in char_freq.items()]
    heapq.heapify(heap)
    
    while len(heap) > 1:
        node1 = heapq.heappop(heap)
        node2 = heapq.heappop(heap)
        
        merged = Node(None, node1.freq + node2.freq)
        merged.left = node1
        merged.right = node2
        
        heapq.heappush(heap, merged)
    
    root = heap[0]  # Root of the Huffman tree
    huffman_codes = generate_codes(root)
    
    return huffman_codes

# Example usage
char_freq = {'a': 5, 'b': 9, 'c': 12, 'd': 13, 'e': 16, 'f': 45}

start_time = time.time()
codes = huffman_encoding(char_freq)
end_time = time.time()

print("Huffman Codes:", codes)
print(f"Execution Time: {end_time - start_time:.6f} seconds")
