// TC = O(N^2 * log N)
// SC = O(1)

#include<bits/stdc++.h>

class Solution {
public:

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<vector<int>> ans;

        // Approach I: Brute Force
        // Iterate through all combinations of four elements
        // and check if their sum is equal to the target.
        // This approach has a time complexity of O(n^4).

        set<vector<int>> st;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    for(int l=k+1; l<n; l++){
                        int sum = nums[i] + nums[j] + nums[k] + nums[l];
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        if(sum == target) st.insert(temp);
                    }
                }
            }
        }
        for(auto &it:st) ans.push_back(it);

        // Approach II: Sorting + Two Pointer
        // Sort the array and use two pointers to find pairs that
        // sum up to the remaining target after fixing two elements.
        // This approach has a time complexity of O(n^3).

        sort(nums.begin(), nums.end());

        for(int i=0; i<n-3; i++){
            if(i != 0 && nums[i] == nums[i-1]) continue;

            for(int j=i+1; j<n-2; j++){
                if(j != i+1 && nums[j] == nums[j-1]) continue;

                long long sum1 = (long long)(nums[i] + nums[j]);
                int low = j+1, high = n-1;

                while(low < high){
                    long long sum2 = (long long)(nums[low] + nums[high]);

                    if(sum2 < (target - sum1)) low++;
                    else if(sum2 > (target - sum1)) high--;
                    else{
                        ans.push_back({nums[i], nums[j], nums[low], nums[high]});
                        while(low < high && nums[low] == nums[low+1]) low++;
                        while(low < high && nums[high] == nums[high-1]) high--;
                        low++; high--;
                    }
                }
            }
        }

        return ans;
    }
};
