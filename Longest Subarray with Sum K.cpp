// TC = O(N)
// SC = O(N)

#include <vector>
#include <unordered_map>
#include <climits>

class Solution {
public:
    int maxLen(vector<int>& nums, int n) {
        unordered_map<int, int> mp; // Create an unordered map to store cumulative sums and their corresponding indices
        
        int sum = 0; // Initialize the cumulative sum to 0
        int maxLength = INT_MIN; // Initialize the maximum length to INT_MIN
        
        mp[0] = -1; // Store an initial sum of 0 at index -1
        
        for (int i = 0; i < n; i++) {
            sum += nums[i]; // Add the current element to the cumulative sum
            
            if (mp.find(sum) != mp.end()) {
                // If the cumulative sum is already present in the map, update the maximum length
                maxLength = max(maxLength, i - mp[sum]);
            } else {
                // If the cumulative sum is encountered for the first time, store its index in the map
                mp[sum] = i;
            }
        }
        
        return (maxLength == INT_MIN) ? 0 : maxLength; // Return 0 if no subarray with sum zero is found, otherwise return the maximum length
    }
};
