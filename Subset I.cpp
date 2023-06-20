// TC = O(2 ^ N)
// SC = O(2 ^ N)

class Solution {
public:
    set<vector<int>> st; // Set to store unique subsets

    // Recursive function to generate subsets
    void solve(int ind, vector<int> &nums, vector<int> &v, int n) {
        // Base case: When all elements are considered, add the subset to the set
        if (ind == n) {
            st.insert(v);
            return;
        }

        v.push_back(nums[ind]); // Include the current element
        solve(ind + 1, nums, v, n); // Recurse with the next index
        v.pop_back(); // Backtrack by removing the current element
        solve(ind + 1, nums, v, n); // Recurse without including the current element

        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> v; // Temporary vector to store subsets
        vector<vector<int>> ans; // Final result
        sort(nums.begin(), nums.end()); // Sort the input array in non-decreasing order

        solve(0, nums, v, n); // Call the recursive function to generate subsets

        for (auto it : st) // Copy the subsets from the set to the result vector
            ans.push_back(it);

        return ans;
    }
};
