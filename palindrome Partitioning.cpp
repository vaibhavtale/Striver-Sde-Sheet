// TC = O(N ^ 3)
// SC = O(N ^ 2)

class Solution {
public:
    // Helper function to check if a substring is a palindrome
    bool isPalindrome(int st, int en, string &s) {
        while (st < en) {
            if (s[st] != s[en]) return false;
            st++;
            en--;
        }
        return true;
    }

    // Recursive function to generate all palindrome partitions
    void solve(int ind, string &s, int n, vector<string> &temp, vector<vector<string>> &ans) {
        if (ind == n) {
            // All characters have been processed, add current partition to the answer
            ans.push_back(temp);
            return;
        }

        for (int i = ind; i < n; i++) {
            if (isPalindrome(ind, i, s)) {
                // Current substring is a palindrome, add it to the temporary partition
                temp.push_back(s.substr(ind, i - ind + 1));
                // Recursively process the remaining substring
                solve(i + 1, s, n, temp, ans);
                // Backtrack by removing the last added substring
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;

        int n = s.length();

        solve(0, s, n, temp, ans);

        return ans;
    }
};
