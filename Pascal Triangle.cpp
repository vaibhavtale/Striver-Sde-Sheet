// TC = O(N^2)
// SC = O(N^2)

// This is pretty easy problem based on Implementation.
// For N rows each row has same element to it's number (1 based Indexing) all are 1's.
// Now we need update all the elments wich are not on boundary means from 1'st column to Row-1'th column.
// Mat[i][j] = Mat[i-1][j-1] + Mat[i-1][j].


class Solution {
public:
    vector<vector<int>> generate(int n) {
      
        vector<vector<int>> ans(n, vector<int> (n, 1));

          for(int i=0; i<n; i++){

              ans[i].resize((i+1), 1);

              for(int j=1; j<i; j++){

                  ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
              }
          }
        return ans;
    }
};
