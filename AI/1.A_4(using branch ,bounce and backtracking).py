def is_safe(board, row, col):
    """
    Check if it's safe to place a queen at board[row][col]
    This function checks only left side for attacking queens
    because the right side of [row][col] hasn't been filled yet
    """
    # Check this row on left side
    for i in range(col):
        if board[row][i] == 1:
            return False

    # Check upper diagonal on left side
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    # Check lower diagonal on left side
    for i, j in zip(range(row, len(board), 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True

def solve_n_queens_util(board, col):
    """
    Recursively place queens on the chessboard
    """
    if col >= len(board):
        return True  # All queens are placed successfully

    for i in range(len(board)):
        if is_safe(board, i, col):
            board[i][col] = 1  # Place queen

            # Recur to place rest of the queens
            if solve_n_queens_util(board, col + 1):
                return True

            board[i][col] = 0  # Backtrack

    return False  # If no queen can be placed in this column

def solve_n_queens(n):
    board = [[0] * n for _ in range(n)]

    if not solve_n_queens_util(board, 0):
        print("Solution does not exist")
        return None

    return board

def print_solution(board):
    if board:
        for row in board:
            print(" ".join('Q' if x == 1 else '-' for x in row))
    else:
        print("No solution found")

if __name__ == "__main__":
    n = int(input("Enter the number of queens: "))
    solution = solve_n_queens(n)
    print_solution(solution)
