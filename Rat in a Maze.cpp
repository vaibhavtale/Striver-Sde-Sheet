// Tc = O(4 ^ N)
// SC = O(N)

class Solution {
public:
    // Arrays to represent possible movements in four directions
    vector<int> delRow = {1, 0, -1, 0};
    vector<int> delCol = {0, -1, 0, 1};
    
    // Recursive function to find paths
    void solve(int row, int col, vector<vector<int>>& arr, int n, vector<string>& ans, string str) {
        // Base cases: out of bounds or cell value is 0
        if (row < 0 || row >= n || col < 0 || col >= n || arr[row][col] == 0) {
            return;
        }
        
        // Reached the destination
        if (row == n - 1 && col == n - 1) {
            ans.push_back(str);
            return;
        }
        
        // Mark the current cell as visited (set to 0)
        arr[row][col] = 0;
        
        // Recursively explore all possible movements
        for (int i = 0; i < 4; i++) {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];
            char direction = "";
            
            // Assign direction based on movement
            if (i == 0) direction = 'U';
            else if (i == 1) direction = 'L';
            else if (i == 2) direction = 'D';
            else direction = 'R';
            
            // Recursively call solve for the next cell
            solve(newRow, newCol, arr, n, ans, str + direction);
        }
        
        // Mark the current cell as unvisited (set to 1)
        arr[row][col] = 1;
        
        return;
    }
    
    vector<string> findPath(vector<vector<int>>& arr, int n) {
        vector<string> ans;
        
        // Start the recursive function from the initial cell (0, 0)
        solve(0, 0, arr, n, ans, "");
        
        return ans;
    }
};
