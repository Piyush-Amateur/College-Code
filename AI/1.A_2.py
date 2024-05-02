class Node:
    def __init__(self, data, level, fval):
        self.data = data  # Puzzle state
        self.level = level  # Depth level of the node in the tree
        self.fval = fval  # Evaluation function value

    def find(self, puz, x):
        """ Locate the position of the blank space represented by 'x' """
        for i in range(len(puz)):
            for j in range(len(puz[i])):
                if puz[i][j] == x:
                    return i, j

    def copy(self):
        """ Create a deep copy of the puzzle state """
        return [row[:] for row in self.data]

    def generate_child(self):
        """ Generate child nodes from the current node by moving the blank space """
        x, y = self.find(self.data, '_')
        val_list = [[x, y - 1], [x, y + 1], [x - 1, y], [x + 1, y]]  # Possible moves
        children = []
        for i in val_list:
            if 0 <= i[0] < len(self.data) and 0 <= i[1] < len(self.data[0]):
                child = self.copy()
                # Swap the blank space with the target element
                child[x][y], child[i[0]][i[1]] = child[i[0]][i[1]], child[x][y]
                child_node = Node(child, self.level + 1, 0)
                children.append(child_node)
        return children

class Puzzle:
    def __init__(self, size):
        self.n = size
        self.open = []
        self.closed = []
        self.visited = set()

    def accept(self):
        """ Accept puzzle state from user input """
        print(f"Enter the {self.n}x{self.n} matrix for the puzzle (use '_' for blank):")
        matrix = []
        for i in range(self.n):
            row = input().split()
            matrix.append(row)
        return matrix

    def display(self, data):
        """ Display the puzzle state """
        for row in data:
            print(' '.join(row))
        print()

    def f(self, start, goal):
        """ Evaluation function for A* (f = g + h) """
        return self.h(start.data, goal) + start.level

    def h(self, start, goal):
        """ Heuristic function to calculate number of misplaced tiles """
        mismatch = sum(start[i][j] != goal[i][j] and start[i][j] != '_' for i in range(self.n) for j in range(self.n))
        return mismatch

    def process(self):
        print("Enter the start state matrix:")
        start = self.accept()
        print("Enter the goal state matrix:")
        goal = self.accept()

        start_node = Node(start, 0, 0)
        start_node.fval = self.f(start_node, goal)
        self.open.append(start_node)
        self.visited.add(tuple(map(tuple, start_node.data)))

        while True:
            if not self.open:
                print("No solution exists.")
                break

            current = self.open.pop(0)
            self.display(current.data)

            if self.h(current.data, goal) == 0:
                print("Goal state reached at level:", current.level)
                break

            children = current.generate_child()
            for child in children:
                child_data_tuple = tuple(map(tuple, child.data))
                if child_data_tuple not in self.visited:
                    child.fval = self.f(child, goal)
                    self.open.append(child)
                    self.visited.add(child_data_tuple)
            self.open.sort(key=lambda x: x.fval)  # Sort the open list based on f value

# Main execution
if __name__ == "__main__":
    puzzle_size = 3  # Define the puzzle size, e.g., 3x3 for the 8-puzzle
    puzzle = Puzzle(puzzle_size)
    puzzle.process()
