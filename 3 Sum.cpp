// TC = O(N^2)
// SC = O(N)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        // Approach I: Brute Force O(N^3)
        // Sorting the array is necessary for this approach
        sort(nums.begin(), nums.end());
        set<vector<int>> st;

        // Iterate through each triplet (i, j, k) with i < j < k
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    if(nums[i] + nums[j] + nums[k] == 0)
                        st.insert({nums[i], nums[j], nums[k]});
                }
            }
        }
       // Combine results from both approaches
              for(auto &it : st)
                  ans.push_back(it);
      
        // Approach II: Sorting + Three Pointer
        for(int i = 0; i < n - 2; i++){
            if(i == 0 || nums[i] != nums[i - 1]){
                int low = i + 1, high = n - 1, sum = 0;

                while(low < high){
                    sum = nums[i] + nums[low] + nums[high];

                    if(sum == 0){
                        ans.push_back({nums[i], nums[low], nums[high]});
                        
                        // Skip duplicate elements
                        while(low < high && nums[low] == nums[low + 1]) low++;
                        while(low < high && nums[high] == nums[high - 1]) high--;

                        low++;
                        high--;
                    }
                    else if(sum > 0){
                        high--; // Decrease high pointer for a smaller value
                    }
                    else{
                        low++; // Increase low pointer for a larger value
                    }
                }
            }
        }
        return ans;
    }
};
