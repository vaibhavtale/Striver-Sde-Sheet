// TC = O(2 ^ N)
// SC = O(N + 2 ^ N)

class Solution {
public:
    void solve(int ind, vector<int>& nums, int tar, int n, vector<int>& v, vector<vector<int>>& ans) {
        // Base case: if the current index reaches the end of the array
        if (ind == n) {
            // If the target sum is achieved, add the current combination to the answer
            if (!tar)
                ans.push_back(v);
            return;
        }

        // Include the current number and recursively call the function
        v.push_back(nums[ind]);
        if (tar - nums[ind] >= 0)
            solve(ind, nums, tar - nums[ind], n, v, ans);
        v.pop_back();

        // Exclude the current number and move to the next index
        solve(ind + 1, nums, tar, n, v, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int tar) {
        int n = nums.size();
        vector<int> v;
        vector<vector<int>> ans;

        solve(0, nums, tar, n, v, ans);

        return ans;
    }
};
