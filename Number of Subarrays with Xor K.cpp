// TC = O(N)
// SC = O(N)

#include <bits/stdc++.h>

using namespace std;

int subarraysXor(vector<int> &arr, int x)
{
    int count = 0; // Variable to store the count of subarrays with XOR equal to x
    
    // Brute Force Approach:
    // Iterate through all subarrays and calculate their XOR
    for (int i = 0; i < arr.size(); i++) {
        int toXor = 0; // Variable to store the XOR value
        
        // Calculate XOR for each subarray starting from index i
        for (int j = i; j < arr.size(); j++) {
            toXor ^= arr[j];
            if (toXor == x)
                count++; // If XOR matches x, increment the count
        }
    }

    // Optimal Approach Using Hashing:
    unordered_map<int, int> mp; // Map to store XOR values and their frequencies
    mp[0] = 1; // Initialize with 0 XOR frequency
    
    int toXor = 0; // Variable to store the XOR value
    
    // Iterate through the array
    for (int i = 0; i < arr.size(); i++) {
        toXor ^= arr[i]; // Calculate XOR
        
        // Check if XOR ^ x exists in the map
        if (mp.find(toXor ^ x) != mp.end()) {
            count += mp[toXor ^ x]; // Add the frequency of XOR ^ x to the count
        }
        
        mp[toXor]++; // Increment the frequency of the current XOR value
    }

    return count; // Return the count of subarrays with XOR equal to x
}

int main()
{
    // Example usage:
    vector<int> arr = {1, 2, 3, 4, 5};
    int x = 3;
    
    int result = subarraysXor(arr, x);
    
    cout << "Count of subarrays with XOR equal to " << x << ": " << result << endl;
    
    return 0;
}
