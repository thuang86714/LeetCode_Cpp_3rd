/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 

Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        //we will first raverse the frist row and col, to see if there's any 0
        //if yes, then mark isZero true. 
        //Hence all cells in the first row or col would be changed into 0 at the end
        //without these bool, you wouldn't know to change the whole first row/col or just come cells in it
        bool isZero_col = false, isZero_row = false;

        //
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0){
                isZero_col = true;
                break;
            }
        }

        for(int j = 0; j < n; j++){
            if(matrix[0][j] == 0){
                isZero_row = true;
                break;
            }
        }
        //dont change the cells in the first row and col
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(isZero_col){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }

        if(isZero_row){
            for(int j = 0; j < n; j++){
                matrix[0][j] = 0;
            }
        }
    }
};