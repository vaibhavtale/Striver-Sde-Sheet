// TC = O(N)
// SC = O(K) ---> number of unique chars

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Initialize a map to store characters and their indices
        unordered_map<char, unsigned long> mp;
        unsigned long ans = 0;
        unsigned long i = 0, j = 0;

        // Iterate through the string
        while (i < s.length() && j < s.length()) {
            // If the current character is not in the map
            if (mp.find(s[j]) == mp.end()) {
                // Add the character and its index to the map
                mp[s[j]] = j;
                j++;
            } else {
                // Update the maximum length if necessary
                ans = max(ans, mp.size());
                // Remove characters from the map until the current character is not in the map
                while (mp.find(s[j]) != mp.end()) {
                    mp.erase(s[i]);
                    i++;
                }
                // Add the current character and its index to the map
                mp[s[j]] = j;
                j++;
            }
        }

        // Update the maximum length if necessary
        ans = max(ans, mp.size());

        return ans;
    }
};
