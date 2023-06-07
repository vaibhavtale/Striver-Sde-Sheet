// TC = O(log m * n)
// SC = O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Get the number of rows and columns in the matrix
        int n = matrix.size();
        int m = matrix[0].size();

        // Check if the target is smaller than the first element in the matrix
        if (target < matrix[0][0]) {
            return false;
        }

        // Check if the target is larger than the last element in the matrix
        if (target > matrix[n - 1][m - 1]) {
            return false;
        }

        // Perform binary search to find the row that may contain the target
        int top = 0;
        int bottom = n - 1;

        while (top < bottom) {
            int mid = (top + bottom) / 2;

            if (matrix[mid][0] > target) {
                bottom = mid - 1;
            } else if (matrix[mid].back() < target) {
                top = mid + 1;
            } else {
                top = mid;
                break;
            }
        }

        // Perform binary search to find the target in the selected row
        int left = 0;
        int right = m - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (matrix[top][mid] == target) {
                return true;
            } else if (matrix[top][mid] < target) {
                left = mid + 1;
            } else if (matrix[top][mid] > target) {
                right = mid - 1;
            }
        }

        return false;
    }
};
