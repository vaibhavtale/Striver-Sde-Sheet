// TC = O(9 ^ (n * n))
// SC = O(n * n)

class Solution {
public:
    // Helper function to check if placing character 'c' at position (row, col) is valid
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c)
                return false; // Check column
            if (board[row][i] == c)
                return false; // Check row
            if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == c)
                return false; // Check 3x3 matrix
        }
        return true; // Placement is valid
    }

    // Backtracking function to solve the Sudoku puzzle
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') { // Find empty cell
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) { // Check if placing 'c' is valid
                            board[i][j] = c; // Place 'c' in the cell
                            if (solve(board)) {
                                return true; // If the puzzle is solved, return true
                            } else {
                                board[i][j] = '.'; // Undo placement and try another value
                            }
                        }
                    }
                    return false; // No valid values for the cell, backtrack
                }
            }
        }
        return true; // Puzzle is solved
    }

    // Function to solve the Sudoku puzzle
    void solveSudoku(vector<vector<char>>& board) {
        solve(board); // Start solving the puzzle
    }
};
