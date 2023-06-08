// TC = O(n), O(NlogN)
// SC = O(n), O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int limit = n / 3;
        vector<int> ans;

        // Approach I: Using a frequency map
        
        map<int, int> freq;
        
        // Count the frequency of each element
        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
        }

        // Check if the frequency exceeds the limit
        for(auto it : freq){
            if(it.second > limit){
                ans.push_back(it.first);
            }
        }
       
--------------------------------------------------------------------------------------------
  
  
        // Approach II: Sorting and counting
        sort(nums.begin(), nums.end());

        int cnt = 1;

        for(int i = 1; i < n; i++){
            // Count consecutive occurrences of the same number
            if(nums[i] == nums[i - 1]){
                cnt++;
            }
            else{
                // Check if the count exceeds the limit
                if(cnt > limit){
                    ans.push_back(nums[i - 1]);
                }
                cnt = 1; // Reset the count for the new number
            }
        }

        // Check the count of the last number
        if(cnt > limit){
            ans.push_back(nums[n - 1]);
        }

        return ans;
    }
};
