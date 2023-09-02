/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:

Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //TC O(m*n) SC O(n)
        int m = matrix.size();
        int n = matrix[0].size();
        int pre, size = 0;
        //dp to store the side of square(return dp[].max * dp[].max)
        vector<int> cur(n, 0);

        //traverse the whole matrix
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int temp = cur[j];
                if(i == 0 || j == 0 || matrix[i][j] == '0'){
                    cur[j] = matrix[i][j] - '0';
                }else{
                    cur[j] = 1 + min(pre, min(cur[j], cur[j - 1]));
                }
                size = max(size, cur[j]);
                pre = temp;
            }
        }

        return size*size;
    }
};