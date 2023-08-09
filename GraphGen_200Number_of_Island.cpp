/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //dfs traverse all elements in the gris to count
        int m = grid.size(), n = grid[0].size(), island = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){  
                if(grid[i][j] == '1'){
                    island++;
                    recur(i, j, grid);
                }
            }
        }
        return island;
    }

    void recur(int i, int j, vector<vector<char>>& grid){
        //base case
        //the cell that's originally is '0' work as natural barrier
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0')return;

        //traversed, avoid redundant traversing
        grid[i][j]='0';

        recur(i + 1, j, grid);
        recur(i - 1, j, grid);
        recur(i, j + 1, grid);
        recur(i, j - 1, grid);
    }
};