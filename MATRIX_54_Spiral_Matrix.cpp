/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //going right->down->left->up->right
        int left = 0, right = matrix[0].size()-1, top = 0, bottom = matrix.size()-1;
        //need a vector to store result
        vector<int> result;

        while(top <= bottom && left <= right){
            //going right
            for(int i = left; i <= right && top <= bottom; i++){
                result.push_back(matrix[top][i]);
            }
            top++;

            //going down
            for(int j = top; j <= bottom && left <= right; j++){
                result.push_back(matrix[j][right]);
            }
            right--;

            //going left
            for(int i = right; i >= left && top <= bottom; i--){
                result.push_back(matrix[bottom][i]);
            }
            bottom--;

            //going up
            for(int j = bottom; j >= top && left <= right; j--){
                result.push_back(matrix[j][left]);
            }
            left++;
        }
        return result;
    }
};