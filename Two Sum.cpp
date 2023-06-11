// TC = O(N)
// SC = O(N)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();

//       Brute force approach:
        Iterate over all pairs of elements and check if their sum equals the target
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] + nums[j] == target) return {i, j};
            }
        }
        return {};

        // Hashing approach (space O(N)):
      
        // Create a map to store the elements and their indices
        map<int, int> m;
        for(int i=0; i<n; i++){
            m[nums[i]] = i;
        }

        // Iterate over the elements and check if the complement exists in the map
        for(auto i=0; i<n; i++){
            if(m.find(target - nums[i]) != m.end() && m[target - nums[i]] != i){
                // Return the indices of the two elements that sum up to the target
                return {i, m[target - nums[i]]};
            }
        }

        return {}; // If no solution is found, return an empty vector
    }
};
