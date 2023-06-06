// TC = O(N^2)
// SC = O(1)


class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size(); // Number of rows
        int m = mat[0].size(); // Number of columns

        // Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }

        int top = 0;
        int right = n - 1;

        // Rotate the elements in concentric squares
        while (top < n && right >= 0) {
            int left = 0;
            int bottom = n - 1;

            // Swap elements in the current square
            while (left < right && bottom > top) {
                swap(mat[bottom][right], mat[top][left]);
                left++;
                bottom--;
            }

            top++;
            right--;
        }
    }
};
