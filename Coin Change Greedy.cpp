// TC = O(N)
// SC = O(1)

#include <bits/stdc++.h> 

int findMinimumCoins(int amount) 
{
    // Create a vector of available coin denominations in descending order
    std::vector<int> nums = {1, 2, 5, 10, 20, 50, 100, 500, 1000};

    // Reverse the order of the denominations for easier iteration
    std::reverse(nums.begin(), nums.end());

    int coins = 0;

    // Iterate through the denominations
    for(int i = 0; i < nums.size(); i++)
    {
        // Check if the current denomination can be used for the remaining amount
        if(nums[i] <= amount)
        {
            // Keep subtracting the current denomination from the amount until it can no longer be subtracted
            while(amount >= nums[i])
            {
                coins++;
                amount -= nums[i];
            }
        }
    }
    
    // Return the total number of coins used
    return coins;
}
