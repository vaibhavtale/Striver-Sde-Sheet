// TC = O(N ^ N)
// SC = O(N ^ N)

class Solution {
public:
    vector<vector<string>> ans; // Store the final solutions

    // Check if it is safe to place a queen at the given position
    bool isSafe(int col, int row, vector<string> &grid, int n) {
        int column = col;

        // Check the left side of the row
        while (column >= 0) {
            if (grid[row][column] == 'Q')
                return false; // There is a queen already placed
            column--;
        }

        int r = row;
        int c = col;

        // Check the upper left diagonal
        while (r < n && c >= 0) {
            if (grid[r][c] == 'Q')
                return false; // There is a queen already placed
            r++;
            c--;
        }

        // Check the lower left diagonal
        while (row >= 0 && col >= 0) {
            if (grid[row][col] == 'Q')
                return false; // There is a queen already placed
            row--;
            col--;
        }

        return true; // It is safe to place a queen at the given position
    }

    // Backtracking function to solve the N-Queens problem
    void solve(int col, vector<string> &grid, int n) {
        if (col == n) {
            ans.push_back(grid); // Found a valid solution, add it to the answer
            return;
        }

        // Try placing a queen in each row of the current column
        for (int row = 0; row < n; row++) {
            if (isSafe(col, row, grid, n)) {
                grid[row][col] = 'Q'; // Place a queen
                solve(col + 1, grid, n); // Recursively solve for the next column
                grid[row][col] = '.'; // Remove the queen (backtrack)
            }
        }
    }

    // Main function to solve the N-Queens problem
    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid(n); // Grid to represent the chessboard
        string s(n, '.');

        // Initialize the grid with empty cells
        for (int i = 0; i < n; i++) {
            grid[i] = s;
        }

        solve(0, grid, n); // Solve the N-Queens problem

        return ans; // Return the solutions
    }
};
