/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
        1.Each row is sorted in non-decreasing order.
        2.The first integer of each row is greater than the last integer of the previous row.
        3.TC must be O(log(m * n))-->Binary Search
        */
        //edge case1: m == 1&& n == 1
        //edge case2: matrix.back().back() < target
        int m = matrix.size(), n = matrix[0].size(), i = 0, j = n - 1;
        while(i < m && j >= 0){
            int cur = matrix[i][j];
            if(cur > target)j--;
            else if(cur < target)i++;
            else return true;
        }
        return false;
    }
};