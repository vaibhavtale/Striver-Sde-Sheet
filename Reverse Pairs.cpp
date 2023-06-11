// TC = O(N log N)
// SC = O(N)

class Solution {
public:
    int n; // Variable to store the size of the input array

    // Helper function to merge two sorted subarrays and count the number of reverse pairs
    int merge(vector<int> &nums, int low, int mid, int high) {
        int count = 0; // Counter for reverse pairs

        int left = low, right = mid + 1, j = mid + 1; // Pointers to track positions in the subarrays
        vector<int> temp; // Temporary vector to store merged subarrays

        // Counting the reverse pairs
        for (int i = low; i <= mid; i++) {
            while (j <= high && nums[i] > 2 * (long long)(nums[j])) {
                j++;
            }
            count += (j - (mid + 1));
        }

        // Merging the two sorted subarrays
        while (left <= mid && right <= high) {
            if (nums[left] > nums[right]) {
                temp.push_back(nums[right++]);
            } else {
                temp.push_back(nums[left++]);
            }
        }
        while (right <= high) {
            temp.push_back(nums[right++]);
        }
        while (left <= mid) {
            temp.push_back(nums[left++]);
        }

        // Copying the merged subarrays back to the original array
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }

        return count;
    }

    // Recursive function to divide the array into smaller subarrays and count reverse pairs
    int divide(vector<int> &nums, int low, int high) {
        if (low >= high) { // Base case: subarray size is 1 or less
            return 0;
        }

        int mid = (high + low) / 2; // Calculate the middle index

        // Divide the array and count the reverse pairs in each subarray
        int inv = divide(nums, low, mid); // Count reverse pairs in the left subarray
        inv += divide(nums, mid + 1, high); // Count reverse pairs in the right subarray
        inv += merge(nums, low, mid, high); // Merge the subarrays and count reverse pairs

        return inv;
    }

    // Function to count the number of reverse pairs in the given array
    int reversePairs(vector<int>& nums) {
        n = nums.size(); // Store the size of the input array

        return divide(nums, 0, n - 1); // Call the recursive function to count reverse pairs
    }
};
