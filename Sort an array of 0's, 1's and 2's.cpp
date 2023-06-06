// Time Complexity: O(n)
// Space Complexity: O(1)

// This is an optimal solution.

// We know that we want all the zeroes in front and all 2's on rear part thats the intuition..
// we gonna use three pointers when i found any zero on arr[mid] i'll simply swap it with arr[low] and as i've got zero at front position,
// i can now move both pointers by 1 cause one index has got sorted. 
// If we get 2 on arr[mid] swap it with arr[high] i.e. last pos and decrement the high pointer cause index at high has got sorted. but dont increment mid, what if we got 0 on that mid pos so check it first 
// Lastly if we get 1 we 'll simply do mid++. cause once zeroes are in front and 2's are on last 1's will get automatically sorted.

#include <bits/stdc++.h>
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                // If current element is 0, swap it with the element at low index
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            } else if (nums[mid] == 2) {
                // If current element is 2, swap it with the element at high index
                swap(nums[mid], nums[high]);
                high--;
            } else {
                // If current element is 1, simply move to the next element
                mid++;
            }
        }
    }
};


