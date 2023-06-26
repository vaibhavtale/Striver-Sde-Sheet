// TC = 2 ^ N
// SC = 2 ^ N

class Solution {
public:

    void solve(int ind, vector<int> &nums, int target, int n, vector<int> &combination, vector<vector<int>> &result) {
        // Base case: If the target sum is reached, add the current combination to the result
        if (target == 0) {
            result.push_back(combination);
            return;
        }

        for (int i = ind; i < n; i++) {
            // Skip duplicates to avoid generating duplicate combinations
            if (i > ind && nums[i] == nums[i - 1])
                continue;

            // If the current number is larger than the remaining target, no need to proceed
            if (target < nums[i])
                break;

            // Include the current number in the combination
            combination.push_back(nums[i]);
            // Recursively explore the remaining numbers
            solve(i + 1, nums, target - nums[i], n, combination, result);
            // Remove the last added number to backtrack and try other possibilities
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> combination;
        vector<vector<int>> result;

        // Sort the input array to handle duplicates efficiently
        sort(nums.begin(), nums.end());

        // Call the helper function to find all valid combinations
        solve(0, nums, target, n, combination, result);

        return result;
    }
};
