// TC = O(N log N)
// SC = O(N)

/*
struct Item{
    int value;
    int weight;
};
*/


class Solution {
public:
    // Custom comparator function to sort pairs in descending order based on the first element
    static bool cmp(pair<double, int>& a, pair<double, int>& b) {
        return a.first > b.first;
    }

    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        
        vector<pair<double, int>> pi;  // Vector to store pairs of value/weight ratios and weights
        
        for(int i = 0; i < n; i++) {
            pi.push_back({(double)((double)arr[i].value / (double)arr[i].weight), arr[i].weight});  // Calculate value/weight ratio and store the pair
        }
        
        sort(pi.begin(), pi.end(), cmp);  // Sort the pairs in descending order based on the value/weight ratio
        
        double ans = 0;  // Variable to store the maximum total value
        
        for(int i = 0; i < pi.size(); i++) {
            if(pi[i].second <= w) {  // If the weight of the item is less than or equal to the remaining capacity
                ans += (pi[i].first * (double)pi[i].second);  // Add the product of value/weight ratio and weight to the answer
                w -= pi[i].second;  // Reduce the remaining capacity
            } else {
                ans += (pi[i].first * (double)w);  // Add the product of value/weight ratio and remaining capacity to the answer
                return ans;  // Return the maximum total value
            }
        }
        
        return ans;  // Return the maximum total value
    }  
};
