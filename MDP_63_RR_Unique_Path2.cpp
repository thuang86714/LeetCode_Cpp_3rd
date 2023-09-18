#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //edge case: obstacleGrid[0][0] == 0;
        if(obstacleGrid[0][0])return 0;

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> dp(n, 0);
        for(int j =0; j < n; j++){
            if(obstacleGrid[0][j]){
                break;
            }else{
                dp[j] =1;
            }
        }
        bool isZero = false;
        for(int i = 1; i < m; i++){
            if(obstacleGrid[i][0] || isZero){
                dp[0] = 0;
                isZero = true;
            }
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j]){
                    dp[j] = 0;
                    continue;
                }else{
                    dp[j] = dp[j] + dp[j - 1];
                }
            }
        }
        return dp.back();

    }
};