// TC = O(N)
// SC = O(N)

#include <vector>
#include <utility>

std::pair<int, int> missingAndRepeating(std::vector<int>& arr, int n) {
    std::vector<int> v(n + 1, 0); // Create a vector to count occurrences of each number
    int repeating = 0, missing = 0; // Variables to store the repeating and missing elements

    // Count the occurrences of each number in the given array
    for (int i = 0; i < n; i++) {
        v[arr[i]]++;
    }

    // Find the repeating and missing elements based on the occurrence counts
    for (int i = 1; i <= n; i++) {
        if (v[i] == 2) {
            repeating = i;
        }

        if (v[i] == 0) {
            missing = i;
        }
    }

    return {missing, repeating}; // Return the pair of missing and repeating elements
}

