// TC = O(Log n)
// SC = O(1)


class Solution {
public:
    double myPow(double x, int n) {
        // Initialize variables
        long double ans = 1.0;
        long long m = n;

        // Handle negative exponent
        if (n < 0) {
            m = -1 * m;
        }

        // Base cases
        if (n == 1) {
            return x;
        }

        if (!n || x == 1) {
            return 1;
        }
      
//       Brute Force
      
      while(--m){
        
        ans = ans * x;
        
      }
      
//       Optimal Approach ____________________________________________

        // Exponentiation by squaring algorithm
        while (m) {
            if (m % 2 == 0) {
                // If exponent is even
                x = x * x;
                m = m / 2;
            } else {
                // If exponent is odd
                ans = ans * x;
                m = m - 1;
            }
        }

        // Handle negative exponent result
        return (n < 0) ? (1 / ans) : ans;  
    }
};
