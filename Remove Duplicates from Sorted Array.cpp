// TC = O(N)
// SC = O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Initialize two pointers: i and j
        // i points to the last element of the unique elements found so far
        // j points to the current element being checked
        int i = 0, j = 1, cnt = 1;

        // Iterate through the array until j reaches the end
        while (j < nums.size()) {
            // If the current element is different from the element at index i,
            // it means we found a new unique element
            if (nums[j] != nums[i]) {
                // Increment the count of unique elements
                cnt++;

                // Move the new unique element to the next position after the last unique element
                nums[i + 1] = nums[j];

                // Move both pointers forward
                i++;
                j++;
            } else {
                // If the current element is the same as the element at index i,
                // move j forward to check the next element
                j++;
            }
        }

        // Return the count of unique elements
        return cnt;
    }
};
