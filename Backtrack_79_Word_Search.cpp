/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 

Follow up: Could you use search pruning to make your solution faster with a larger board?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        //TC O(NM4^L), where L is the length of the word. 
        //SC O(L) : where L is the length of the given word. This space is used for recursion stack.
        int pos = 0;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(recur(i, j, pos, board, word))return true;
            }
        }
        return false;
    }

    bool recur(int i , int j, int pos, vector<vector<char>>& board, string word){
        //base case1
        if(pos >= word.size())return true;
        //base case2
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[pos])return false;

        char temp = board[i][j];
        board[i][j] = '*';//The same letter cell may not be used more than once.
        bool res = recur(i + 1, j, pos+1, board, word) || recur(i - 1, j, pos+1, board, word) || recur(i, j + 1, pos+1, board, word) || recur(i, j - 1, pos+1, board, word);
        board[i][j] = temp;
        return res;
    }
};