// TC = O(N)
// SC = O(1)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // Initialize counters
        int cnt = 0; // Counter for consecutive ones
        int ans = 0; // Maximum consecutive ones found so far

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            // If the current element is 0, reset the counter
            if (nums[i] == 0) {
                cnt = 0;
            } else {
                // If the current element is 1, increment the counter
                cnt++;
            }

            // Update the maximum consecutive ones if necessary
            ans = max(ans, cnt);
        }

        // Return the maximum consecutive ones
        return ans;
    }
};
