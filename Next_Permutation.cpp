// TC = O(N^2)
// SC = O(N)

// Uff's what a frustrating question it was for me, it almost took me 2 - 3 hours.
// Insteading of just thinking it like a array i started to think as a number.
// Then later i got the intution to change the rightmost smaller element with the greater one on it's right.
// store that index and after that index just sort the arr.
// Test case with zero needs to be taken care of. 

class Solution {
public:

    void nextPermutation(vector<int>& nums) {
        
        int ind = -1, n = nums.size(), index = -1, x;

        for(int i=n-1; i>=0; i--){

            for(int j=i-1; j>=0; j--){

                if(nums[j] < nums[i] ){
                  
                    if(j > index){
                         x = i;         
                        index = j;
                    }
                }
            }
        } 

        if(index == -1){
            sort(nums.begin(), nums.end());
            return;
        }
        
        int temp = nums[x];
        nums[x] = nums[index];
        nums[index] = temp;

        index++;
        sort(nums.begin()+index, nums.end());
        
        
    }
};
