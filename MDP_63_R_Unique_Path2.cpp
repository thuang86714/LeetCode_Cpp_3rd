/*
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 

Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.
*/

#include <bits/stdc++.h>
using namespace std;

//SC optimized ver
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //TC O(m*n) SC O(n)
        //edge case obstacleGrid[0][0] == 0;
        if(obstacleGrid[0][0])return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(n, 0);

        //traverse the first row
        for(int j = 0; j < n; j++){
            //if there's an obstacle in the way, then in this case there's no way to bypass
            //it's blocked
            if(obstacleGrid[0][j]){
                break;
            }
            dp[j] = 1;
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
                }
                dp[j] = dp[j] + dp[j - 1];
            }
        }

        return dp[n - 1];
    }
};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //TC O(m*n) SC O(m*n)
        //edge case obstacleGrid[0][0] == 0;
        if(obstacleGrid[0][0])return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        //traverse the first row
        for(int j = 0; j < n; j++){
            //if there's an obstacle in the way, then in this case there's no way to bypass
            //it's blocked
            if(obstacleGrid[0][j]){
                break;
            }
            dp[0][j] = 1;
        }

        //traverse the first col
        for(int i = 0; i < m; i++){
            //if there's an obstacle in the way, then in this case there's no way to bypass
            //it's blocked
            if(obstacleGrid[i][0]){
                break;
            }
            dp[i][0] = 1;
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j])continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m- 1][n - 1];
    }
};