#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, bottom = m - 1, right = n - 1, left = 0;

        while(top <= bottom && left <= right){
            for(int j = left; j <= right&& top <= bottom; j++){
                res.push_back(matrix[top][j]);
            }
            top++;
            
            for(int i = top; i <= bottom && left <= right; i++){
                res.push_back(matrix[i][right]);
            }
            right--;

            for(int j = right; j >= left && top <= bottom; j--){
                res.push_back(matrix[bottom][j]);
            }
            bottom--;

            for(int i = bottom; i >= top && left <= right; i--){
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        return res;
    }
};