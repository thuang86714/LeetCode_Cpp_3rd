/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4

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
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //TC O(m*n), SC O(n)
        //pre would work as the last element of the same row
        int m = matrix.size(), n = matrix[0].size(), size = 0, pre;
        vector<int> cur(n);

        //edge case: matrix.suze() == 0
        if(matrix.empty())return 0;

        //traverse all elements just once
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int temp = cur[j];
                if(i == 0 || j == 0 || matrix[i][j] == '0'){
                    cur[j] = matrix[i][j] - '0';
                }else{//here cur work as elements from the last row
                    cur[j] = 1 + min(pre, min(cur[j], cur[j - 1]));
                }
                size = max(size, cur[j]);
                pre = temp;
            }
        }
        return size*size;
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //TC O(m*n), SC O(2n)
        //pre would work as the last element of the same row
        int m = matrix.size(), n = matrix[0].size(), size = 0;
        vector<int> cur(n);
        vector<int> pre(n);
        //edge case: matrix.suze() == 0
        if(matrix.empty())return 0;

        //traverse all elements just once
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0 || matrix[i][j] == '0'){
                    cur[j] = matrix[i][j] - '0';
                }else{//here cur work as elements from the last row
                    cur[j] = 1 + min(cur[j - 1], min(pre[j], pre[j - 1]));
                }
                size = max(size, cur[j]);
            }
            fill(pre.begin(), pre.end(), 0);
            swap(pre, cur);
        }
        return size*size;
    }
};