#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int island = 0, m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    island++;
                    recur(grid, i, j);
                }
            }
        }
        return island;
    }

    void recur(vector<vector<char>>& grid, int i, int j){
        //base case
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1')return;

        grid[i][j] = '#';

        recur(grid, i + 1, j);
        recur(grid, i - 1, j);
        recur(grid, i, j + 1);
        recur(grid, i, j - 1);
    }
};