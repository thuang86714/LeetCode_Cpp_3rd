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
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //credit to jianchao-li
        //TC O(m*n), SC O(m*n)
        //need to check if cell.val == 1
        
        //we first traverse all elements in the first col and row, if cell.val != 1, 
        //then dp of that cell is 1, since we could only move right or down

        //edge case 1: obstacleGrid[0][0] == 1
        //edge case2: m ==1, n ==1
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        //a vector to store dp value
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        dp[1][0] = 1;//could be dp[0][1] = 1, doesn't matter
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(obstacleGrid[i - 1][j - 1] == 0){
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};

class Solution {
public: 
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> pre(m, 0);
        vector<int> cur(m, 0);
        for (int i = 0; i < m; i++) {
            if (!obstacleGrid[i][0])
                pre[i] = 1;
            else break;
        }
        for (int j = 1; j < n; j++) {
            bool flag = false;
            if (!obstacleGrid[0][j]) {
                cur[0] = pre[0];
                if (cur[0]) flag = true; 
            }
            else cur[0] = 0;
            for (int i = 1; i < m; i++) {
                if (!obstacleGrid[i][j]) {
                    cur[i] = cur[i - 1] + pre[i];
                    if (cur[i]) flag = true;
                }
                else cur[i] = 0;
            }
            if (!flag) return 0;
            swap(pre, cur);
        }
        return pre[m - 1];
    }
}; 

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //credit to jianchao-li
        //SC O(n)
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> cur(m, 0);
        for (int i = 0; i < m; i++) {
            if (!obstacleGrid[i][0])
                cur[i] = 1;
            else break;
        }
        for (int j = 1; j < n; j++) {
            bool flag = false;
            if (obstacleGrid[0][j])
                cur[0] = 0;
            else flag = true;
            for (int i = 1; i < m; i++) {
                if (!obstacleGrid[i][j]) {
                    cur[i] += cur[i - 1]; 
                    if (cur[i]) flag = true;
                }
                else cur[i] = 0; 
            }
            if (!flag) return 0;
        }
        return cur[m - 1];
    }
};