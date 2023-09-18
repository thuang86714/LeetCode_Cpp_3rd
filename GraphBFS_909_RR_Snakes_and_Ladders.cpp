#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int label = 1;
        vector<pair<int, int>> cell(n*n+1);
        vector<int> cols(n);
        for(int i = 0; i < n; i++){
            cols[i] = i;
        }

        for(int row = n -1; row >= 0; row--){
            for(int col:cols){
                cell[label++] = {row, col};
            }
            reverse(cols.begin(), cols.end());
        }

        vector<int> dp(n*n+1, -1);
        dp[1] = 0;
        
        //BFS
        queue<int> q;
        q.push(1);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int next = node+1; next <= min(node+6, n*n); next++){
                int row = cell[next].first;
                int col = cell[next].second;
                int dest;
                if(board[row][col] != -1){
                    dest = board[row][col];
                }else{
                    dest = next;
                }
                if(dp[dest] == -1){
                    dp[dest] = dp[node]+1;
                    q.push(dest);
                }
                
            }
        }

        return dp.back();
    }
};