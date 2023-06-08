//TC = O(n)
//SC = O(n^2), O(n), O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        // Approach 1: Using a Map to Count Frequencies
        map<int, int> mp;  // Map to store the frequency of each element

        for (auto it : nums) {
            mp[it]++;  // Increment the frequency of the element
        }

        for (auto it : mp) {
            if (it.second >= 2) {
                return it.first;  // Return the element with frequency >= 2 (duplicate)
            }
        }

        // If no duplicate found, return -1

        // Approach 2: Using an Array to Count Frequencies
        int n = nums.size();
        vector<int> v(n, 0);  // Array to store the frequency of each element

        for (auto it : nums) {
            v[it]++;  // Increment the frequency of the element
        }

        for (int i = 0; i < n; i++) {
            if (v[i] >= 2) {
                return i;  // Return the element with frequency >= 2 (duplicate)
            }
        }

        // If no duplicate found, return -1

        // Approach 3: Sorting and Checking Adjacent Elements
        sort(nums.begin(), nums.end());  // Sort the array in ascending order

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                return nums[i];  // Return the duplicate element found
            }
        }

        // If no duplicate found, return -1

        return -1;
    }
};
