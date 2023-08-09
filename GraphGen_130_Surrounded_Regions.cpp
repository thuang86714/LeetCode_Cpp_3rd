/*
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.
Example 2:

Input: board = [["X"]]
Output: [["X"]]
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.
*/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        //traverse the first and last row, since if =='O', it would unconditionally be still 'O'
        for(int i = 0; i < n; i++){
            if(board[0][i] == 'O'){
                dfs(board, 0, i);
            }
            if(board[m - 1][i] == 'O'){
                dfs(board, m - 1, i);
            }
        }

        //traverse the first and last column, since if =='O', it would unconditionally be still 'O'
        for(int j = 0; j < m; j++){
            if(board[j][0] == 'O'){
                dfs(board, j, 0);
            }
            if(board[j][n - 1] == 'O'){
                dfs(board, j, n - 1);
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j){
        //base case
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O')return;

        board[i][j] = '#';

        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i , j + 1);
        dfs(board, i , j - 1);
    }
};
