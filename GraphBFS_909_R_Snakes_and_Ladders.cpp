/*
You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do the following:

Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
The game ends when you reach the square n2.
A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 do not have a snake or ladder.

Note that you only take a snake or ladder at most once per move. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.

For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
Return the least number of moves required to reach the square n2. If it is not possible to reach the square, return -1.

 

Example 1:
Input: board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
Output: 4
Explanation: 
In the beginning, you start at square 1 (at row 5, column 0).
You decide to move to square 2 and must take the ladder to square 15.
You then decide to move to square 17 and must take the snake to square 13.
You then decide to move to square 14 and must take the ladder to square 35.
You then decide to move to square 36, ending the game.
This is the lowest possible number of moves to reach the last square, so return 4.
Example 2:

Input: board = [[-1,-1],[-1,3]]
Output: 1
 

Constraints:

n == board.length == board[i].length
2 <= n <= 20
board[i][j] is either -1 or in the range [1, n2].
The squares labeled 1 and n2 do not have any ladders or snakes.

*/

#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        //Return the least number of moves required to reach the square n2
        int n = board.size(), label = 1;
        //cell would store the (x, y)of all cells in board
        vector<pair<int, int>> cell(n*n+1);

        //x-axix 
        vector<int> cols(n);
        for(int i = 0; i < n; i++){
            cols[i]= i;
        }

        for(int row = n - 1; row >= 0; row--){
            for(int col:cols){
                cell[label++] = {row, col};
            }
            //go ZigZag
            reverse(cols.begin(), cols.end());
        }
        //record steps from cell1 to celln*n
        vector<int> dp(n*n+1, -1);
        dp[1] = 0;//you dont have to move to be at cell1
        //every step is a level of a tree
        queue<int> q;
        q.push(1);

        //bfs
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            //here we simulate the rolling dice
            for(int next = cur + 1; next <= min(cur+6, n*n); next++){
                int row = cell[next].first;
                int col = cell[next].second;
                int dest;
                //meaning there's a ladder or snake
                if(board[row][col] != -1){
                    dest = board[row][col];
                }else{
                    dest = next;
                }

                if(dp[dest] == -1){
                    dp[dest] = dp[cur] + 1;
                    q.push(dest);
                }
            }

        }
        return dp[n*n];
    }
};