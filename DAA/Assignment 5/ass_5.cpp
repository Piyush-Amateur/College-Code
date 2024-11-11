#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

void printBoard(const vector<vector<int>>& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(const vector<vector<int>>& board, int row, int col, int n) {
    // Check this column on upper rows
    for (int i = 0; i < row; i++) {
        if (board[i][col])
            return false;
    }

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    // Check upper diagonal on right side
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j])
            return false;
    }

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int row, int n) {
    if (row >= n) {
        printBoard(board, n);
        return true;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;  // Place queen
            if (solveNQueens(board, row + 1, n))
                return true;
            board[row][col] = 0;  // Backtrack
        }
    }

    return false;
}

void nQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    // Place the first queen at a given position (first row, first column)
    board[0][0] = 1;
    if (!solveNQueens(board, 1, n)) {
        cout << "No solution found" << endl;
    }
}

int main() {
    int n = 8;
    
    auto start = chrono::high_resolution_clock::now();
    nQueens(n);
    auto end = chrono::high_resolution_clock::now();
    
    chrono::duration<double> execution_time = end - start;
    cout << "Execution Time: " << execution_time.count() << " seconds" << endl;

    return 0;
}
