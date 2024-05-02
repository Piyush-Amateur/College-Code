class Node:
    def __init__(self, data, level, fval):
        self.data = data
        self.level = level
        self.fval = fval
    
    def find(self, puz, x):
        for i in range(len(puz)):
            for j in range(len(puz[i])):
                if (puz[i][j] == x):
                    return i, j

    def copy(self):
        ans = []
        for i in self.data:
            t = []
            for j in i:
                t.append(j)
            ans.append(t)
        return ans

    def generate_child(self):
        ans = []
        x, y = self.find(self.data, '_')
        val_list = [[x, y+1], [x, y-1], [x+1, y], [x-1, y]]
        for i in val_list:
            if (0 <= i[0] < len(self.data) and 0 <= i[1] < len(self.data[0])):
                t = self.copy()
                temp = t[x][y]
                t[x][y] = t[i[0]][i[1]]
                t[i[0]][i[1]] = temp

                child_node = Node(t, self.level+1, 0)
                ans.append(child_node)
        return ans

class Puzzle:
    def __init__(self, size):
        self.n = size
        self.open = []
        self.closed = []

    def accept(self):
        arr = []
        for i in range(self.n):
            t = input().split(" ")
            arr.append(t)
        return arr

    def display(self, data):
        for i in data:
            for j in i:
                print(j, end=" ")
            print()

    def display_arrow(self):
        print("\n\n-->")

    def f(self, start, goal):
        return self.h(start.data, goal)+start.level

    def h(self, start, goal):
        ans = 0
        for i in range(self.n):
            for j in range(self.n):
                if (start[i][j] != goal[i][j] and start[i][j] != '_'):
                    ans += 1
        return ans

    def process(self):
        # Accept Start State and Goal State
        print("Enter The Start State:- \n")
        start = self.accept()
        print("Enter the Goal State:- \n")
        goal = self.accept()

        start = Node(start, 0, 0)
        start.fval = self.f(start, goal)
        self.open.append(start)

        print("="*30, "\n")

        while True:
            curr = self.open[0]

            self.display(curr.data)
            self.display_arrow()

            if self.h(curr.data, goal) == 0:
                break
            
            for i in curr.generate_child():
                i.fval = self.f(i, goal)
                self.open.append(i)

            self.closed.append(curr)
            del self.open[0]

            self.open.sort(key=lambda x: x.fval, reverse=False)


# -----------------------Main Program-----------------------#
puz = Puzzle(3)
puz.process()
