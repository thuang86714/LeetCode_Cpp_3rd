/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //TC O(n), SC O(1)(other than the answer itself)
        vector<int> result;
        //do a spiral traverse of all elements in matrix, the 4 variables work as coordinate
        int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;

        while(top <= bottom && left <= right){
            //going left
            for(int j = left; j <= right && top <= bottom; j++){
                result.push_back(matrix[top][j]);
            }
            top++;

            //going down
            for(int i = top; i <= bottom && left <= right; i++){
                result.push_back(matrix[i][right]);
            }
            right--;

            //goint left
            for(int j = right; j >= left && top <= bottom; j--){
                result.push_back(matrix[bottom][j]);
            }
            bottom--;

            for(int i = bottom; i >= top && left <= right; i--){
                result.push_back(matrix[i][left]);
            }
            left++;
        }
        return result;
    }
};
