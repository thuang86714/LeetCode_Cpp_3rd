#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        //check the first and last col && row
        //since there are on the border, if there are O, they would always be O
        int m = board.size(), n = board[0].size();
        //checking the first and last col
        for(int i = 0 ; i < m; i++){
            if(board[i][0] == 'O'){
                recur(board, i, 0);
            }
        }

        for(int i = 0 ; i < m; i++){
            if(board[i][n -1] == 'O'){
                recur(board, i, n - 1);
            }
        }

        //checking the first and last row
        for(int j =0; j < n; j++){
            if(board[0][j] == 'O'){
                recur(board, 0, j);
            }
        }

        for(int j =0; j < n; j++){
            if(board[m - 1][j] == 'O'){
                recur(board, m - 1, j);
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] != '#'){
                    board[i][j] = 'X';
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }

    void recur(vector<vector<char>>& board, int i, int j){
        //base case
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O')return;

        board[i][j] = '#';

        recur(board, i + 1, j);
        recur(board, i - 1, j);
        recur(board, i, j + 1);
        recur(board, i, j - 1);
    }
};