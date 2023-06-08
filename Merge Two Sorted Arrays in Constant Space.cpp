// TC = O(n + m)
// SC = O(1)

#include <bits/stdc++.h>

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m + n - 1;  // Index of the last element in the merged array
        int i = m - 1;  // Index of the last element in nums1
        int j = n - 1;  // Index of the last element in nums2
        
        // Merge the arrays from the last element to the first
        while (j >= 0 && i >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[last] = nums1[i];  // Copy the larger element from nums1
                i--;  // Move the pointer of nums1 one step back
                last--;  // Move the pointer of the merged array one step back
            } else {
                nums1[last] = nums2[j];  // Copy the larger element from nums2
                j--;  // Move the pointer of nums2 one step back
                last--;  // Move the pointer of the merged array one step back
            }
        }
        
        // If there are any remaining elements in nums1, copy them to the merged array
        while (i >= 0) {
            nums1[last--] = nums1[i--];  // Copy the remaining elements from nums1
        }
        
        // If there are any remaining elements in nums2, copy them to the merged array
        while (j >= 0) {
            nums1[last--] = nums2[j--];  // Copy the remaining elements from nums2
        }
    }
};
