import time

def print_board(board, n):
    for i in range(n):
        row = ""
        for j in range(n):
            row += "Q " if board[i][j] else ". "
        print(row)
    print()

def is_safe(board, row, col, n):
    # Check this column on upper rows
    for i in range(row):
        if board[i][col]:
            return False
    
    # Check upper diagonal on left side
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j]:
            return False

    # Check upper diagonal on right side
    for i, j in zip(range(row, -1, -1), range(col, n)):
        if board[i][j]:
            return False

    return True

def solve_nqueens(board, row, n):
    if row >= n:
        print_board(board, n)
        return True

    for col in range(n):
        if is_safe(board, row, col, n):
            board[row][col] = 1  # Place queen
            if solve_nqueens(board, row + 1, n):
                return True
            board[row][col] = 0  # Backtrack if placing the queen leads to no solution

    return False

def nqueens(n):
    board = [[0] * n for _ in range(n)]
    # Place the first queen at a given position (first row, first column for example)
    board[0][0] = 1
    if not solve_nqueens(board, 1, n):
        print("No solution found")
    return board

# Example usage
n = 8
start_time = time.time()
nqueens(n)
end_time = time.time()

print(f"Execution Time: {end_time - start_time:.6f} seconds")
