// TC = O(N log N)
// SC = O(N)

#include <bits/stdc++.h> 

// Function to merge two sorted arrays and count inversions
long long merge(long long *nums, long long low, long long mid, long long high){

    long long count = 0;

    long long left = low, right = mid+1, j = mid+1;
    vector<long long> temp;

    // Counting inversions
    for(int i=low; i<=mid; i++){
        while(j <= high && nums[i] > nums[j])
            j++;
        count += (j - (mid+1));
    }

    // Merging the sorted arrays
    while(left <= mid && right <= high){
        if(nums[left] > nums[right]){
            temp.push_back(nums[right++]);
        }
        else{
            temp.push_back(nums[left++]);
        }
    }
    while(right <= high) temp.push_back(nums[right++]);
    while(left <= mid) temp.push_back(nums[left++]);

    // Copying the merged array back to the original array
    for(int i=low; i<=high; i++){
        nums[i] = temp[i - low];
    }

    return count;
}

// Function to divide the array and recursively count inversions
long long divide(long long* nums, long long low, long long high){

    if(low >= high) return 0;

    long long mid = (high + low) / 2;

    // Recursively divide, count inversions, and merge the arrays
    long long inv = divide(nums, low, mid);
    inv += divide(nums, mid+1, high);
    inv += merge(nums, low, mid, high);

    return inv;
}

// Function to get the total number of inversions in the array
long long getInversions(long long *nums, int n){
    return divide(nums, 0, n-1);
}
