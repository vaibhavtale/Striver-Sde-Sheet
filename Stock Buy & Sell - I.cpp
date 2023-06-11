// TC = O(N)
// SC = O(1)

class Solution {
public:
    int n; // Number of elements in the input vector

    // Function to recursively solve the problem
    int solve(int ind, int buy, vector<int> &cost, int k, vector<vector<int>> &dp){
        if(ind >= n || k <= 0) return 0; // Base case: if index is out of bounds or k is 0, return 0
        
        if(dp[ind][buy] != -1) return dp[ind][buy]; // If the subproblem is already solved, return the stored value
        
        int profit = 0;
        
        if(buy){
            // If we are buying at the current index, we have two options:
            // 1. Skip the current index and continue without buying (buy = 0)
            // 2. Buy at the current index and move to the next index (buy = 1)
            profit = max(solve(ind+1, 0, cost, k, dp) - cost[ind], solve(ind+1, 1, cost, k, dp));
        }
        else if(!buy){
            // If we are not buying at the current index, we have two options:
            // 1. Buy at the current index and decrement k (buy = 1, k-1)
            // 2. Skip the current index and continue without buying (buy = 0, k)
            profit = max(solve(ind+1, 1, cost, k-1, dp) + cost[ind], solve(ind+1, 0, cost, k, dp));
        }
        
        dp[ind][buy] = profit; // Store the calculated profit for the current index and buy state
        
        return profit;
    }

    // Function to calculate the maximum profit
    int maxProfit(vector<int>& cost) {
        n = cost.size(); // Set the number of elements in the input vector
        
        // Uncomment the code below to solve the problem using a dynamic programming approach
        // vector<vector<int>> dp(n, vector<int>(2, -1)); // Initialize the dp table with -1
        
        // Code below to solve the problem using a brute-force approach
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ans = max(ans, (cost[j] - cost[i]));
            }
        }
        
        // Code below to solve the problem using a stack-based approach
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            if(st.empty()){
                st.push(cost[i]);
            }
            else if(st.top() < cost[i]){
                st.pop();
                st.push(cost[i]);
            }
            else{
                ans = max(ans, st.top() - cost[i]);
            }
        }
        
//         Most Optimal Solution using Dynamic Programming / Kadanes Algo
      
        int minValue = cost[0], profit = 0; // Initialize the minimum value and profit
        
        // Loop through the input vector to calculate the minimum value and maximum profit
        for(int i=0; i<n; i++){
            minValue = min(minValue, cost[i]); // Update the minimum value if necessary
            profit = max(profit, cost[i] - minValue); // Calculate the maximum profit
        }
        
        return profit; // Return the maximum profit
        
        // Uncomment the code below to solve the problem using the recursive solve function
        // return solve(0,
