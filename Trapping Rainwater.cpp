// TC = O(N)
// SC = O(N)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> width(n, 0); // Array to store the width of each bar

        int maxi = 0, maxi2 = 0; // Variables to keep track of the maximum height encountered

        stack<int> st, st2; // Stacks to keep track of decreasing heights

        // Iterate over each bar from left to right
        for(int i=0; i<n; i++){
            if(st.empty()){
                width[i] = 0; // No bars on the left, so the width is 0
                st.push(height[i]); // Push the current height to the stack
            }
            else if(st.top() >= height[i]){
                width[i] = st.top(); // Width is determined by the current height
            }
            else if(st.top() < height[i]){
                width[i] = st.top(); // Width is determined by the current height
                st.push(height[i]); // Push the current height to the stack
            }

            // Without Stack
            width[i] = maxi; // Update width using the maximum height encountered so far
            maxi = max(maxi, height[i]); // Update the maximum height encountered
        }

        // Iterate over each bar from right to left
        for(int i=n-1; i>=0; i--){
            if(st2.empty()){
                width[i] = 0; // No bars on the right, so the width is 0
                st2.push(height[i]); // Push the current height to the stack
            }
            else if(st2.top() >= height[i]){
                width[i] = min(width[i], st2.top()); // Width is determined by the current height
            }
            else if(st2.top() < height[i]){
                width[i] = 0; // Width is 0 since there is no higher bar on the right
                st2.push(height[i]); // Push the current height to the stack
            }

            // Without Stack
            width[i] = min(width[i], maxi2); // Update width using the maximum height encountered so far
            maxi2 = max(maxi2, height[i]); // Update the maximum height encountered
        }

        int res = 0; // Variable to store the final result

        // Calculate the trapped water by subtracting the height of each bar from its corresponding width
        for(int i=0; i<n; i++){
            if(width[i] - height[i] > 0) res += width[i] - height[i];
        }

        return res; // Return the total trapped water
    }
};
