#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int size= 0, pre;
        vector<int> dp(n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int temp = dp[j];
                if(i == 0 || j == 0 || matrix[i][j] == '0'){
                    dp[j] = matrix[i][j] - '0';
                }else{
                    dp[j] = 1 + min(pre, min(dp[j], dp[j - 1]));
                }
                size = max(size, dp[j]);
                pre = temp;
            }
        }
        return size*size;
    }
};