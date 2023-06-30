// TC = O(N !)
// SC = O(1)

class Solution {
public:
    // Helper function to generate all permutations
    void result(vector<int> &nums, int ind, int n, vector<vector<int>> &ans) {
        if (ind == n) {
            // All elements have been processed, add current permutation to the answer
            ans.push_back(nums);
            return;
        }

        for (int i = ind; i <= n; i++) {
            // Swap the current element with the element at index ind
            swap(nums[i], nums[ind]);
            
            // Recursively generate permutations for the remaining elements
            result(nums, ind + 1, n, ans);
            
            // Restore the original order by swapping back the elements
            swap(nums[i], nums[ind]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        result(nums, 0, nums.size() - 1, ans);
        return ans;
    }
};
