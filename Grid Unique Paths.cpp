// TC = O(n * m)
// SC = O(n * m)

class Solution {
public:
    int row, col;

    // Recursive function to calculate the number of unique paths
    int solve(int i, int j, vector<vector<int>>& dp) {
        // Base cases
        if (i >= row || j >= col) return 0; // Out of bounds
        if (i == row - 1 && j == col - 1) return 1; // Reached destination

        // Check if the result is already calculated
        if (dp[i][j] != -1) return dp[i][j];

        // Calculate the number of unique paths by moving down and right
        int down = solve(i + 1, j, dp);
        int right = solve(i, j + 1, dp);

        // Store the result in the dp table and return it
        return dp[i][j] = (down + right);
    }

    int uniquePaths(int m, int n) {
        // Set the number of rows and columns
        row = m;
        col = n;

        // Create a dp table to store intermediate results
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // Call the solve function to calculate the number of unique paths
        return solve(0, 0, dp);
    }
};
