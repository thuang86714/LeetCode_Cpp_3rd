/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200
*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //TC O(m*n), SC O(m)
        //edge case: m ==1
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(m, grid[0][0]);

        //getting dp val if we go all the way down first
        for(int i = 1; i < m; i++){
            dp[i] = dp[i - 1] + grid[i][0];
        }

        //then we try to moving right
        for(int j = 1; j < n; j++){
            dp[0] += grid[0][j];//moving right
            for(int i = 1; i < m; i++){
                dp[i] = min(dp[i], dp[i - 1]) + grid[i][j];
            }
        }

        //return dp[m - 1], the dp val of bottom-right cell, aka destination
        return dp[m - 1];
    }
};