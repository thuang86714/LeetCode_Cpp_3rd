#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //TC O(m*n), SC O(n)
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n, 0);
        dp[0] = grid[0][0];
        for(int j = 1; j < n; j++){
            dp[j] = dp[j - 1] + grid[0][j];
        }

        for(int i = 1; i < m; i++){
            dp[0] += grid[i][0];
            for(int j = 1; j < n; j++){
                dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
            }
        }

        return dp.back();
    }
};