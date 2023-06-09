// TC = O(N^2)
// SC = O(N)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Get the number of rows and columns in the matrix
        int n = matrix.size();
        int m = matrix[0].size();

        // Create boolean arrays to track rows and columns that contain zeros
        vector<bool> rows(n, false);
        vector<bool> cols(m, false);

        // Traverse through the matrix to identify rows and columns with zeros
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }

        // Set the corresponding rows and columns to zero
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(rows[i] || cols[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
