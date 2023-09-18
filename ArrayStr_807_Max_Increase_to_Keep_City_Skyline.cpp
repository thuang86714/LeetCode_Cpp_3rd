#include <vector>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> col;
        vector<int> row;
        for(int i = 0; i < n; i++){//col first
            int maxi = -1;
            for(int j = 0; j < n; j++){
                maxi = max(maxi, grid[i][j]);
            }
            col.push_back(maxi);
        }

        for(int j = 0; j < n; j++){
            int maxi = -1;
            for(int i = 0; i < n; i++){
                maxi = max(maxi, grid[i][j]);
            }
            row.push_back(maxi);
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(min(col[i], row[j]) - grid[i][j] > 0){
                    sum += min(col[i], row[j]) - grid[i][j];
                }
            }
        }
        return sum;
    }
};