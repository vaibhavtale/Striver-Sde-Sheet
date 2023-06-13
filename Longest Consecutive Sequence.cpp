// TC = O(N)
// SC = O(N)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        // Create an unordered_map to store the frequency of each number
        unordered_map<int, int> mp;
        
        int n = nums.size();
        int ans = INT_MIN;

        // Count the frequency of each number in the input vector
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        // Iterate over each number in the input vector
        for(auto it : nums){
            int cnt = 0;

            // Check if the previous number (it-1) exists in the unordered_map
            if(mp.find(it - 1) == mp.end()){
                // If the previous number does not exist, it means this number is the start of a consecutive sequence
                // Iterate forward to find the length of the sequence
                while(mp.find(it) != mp.end()){
                    // Remove the current number from the unordered_map
                    mp.erase(it);
                    // Increment the count and move to the next number
                    cnt++;
                    it++;
                }
            }

            // Update the maximum length of consecutive sequence found so far
            ans = max(ans, cnt);
        }

        // If no consecutive sequence is found, return 0; otherwise, return the maximum length
        return (ans == INT_MIN) ? 0 : ans;
    }
};
