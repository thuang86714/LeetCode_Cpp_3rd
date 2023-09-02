/*
According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 25
board[i][j] is 0 or 1.
 

Follow up:

Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array (i.e., live cells reach the border). How would you address these problems?

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        //TC O(m*n) SC O(1)
        int m = board.size(), n = board[0].size();

        //traverse all elements to determine dead or alive in the next round
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n; j++){
                int count = 0;
                for(int I = max(0, i - 1); I < min(i + 2, m); I++){
                    for(int J = max(0, j - 1); J < min(j + 2, n);J++){
                        // in the 3x3 grid, see how many live cell
                        //if board[I][J] means the cell has been transformed into next round
                        //to know it's dead or alive in the next round -2;
                        count += board[I][J] >1? board[I][J]-2: board[I][J];
                    }
                }
                if(count ==3 || count - board[i][j] == 3)board[i][j]+= 2;
            }
        }

        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] > 1)board[i][j] = 1;
                else board[i][j] = 0;
            }
        }
    }
};