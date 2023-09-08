#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(backtrack(board, word, 0, i, j))return true;
            }
        }
        return false;
    }

    bool backtrack(vector<vector<char>>& board, string word, int pos, int i, int j){
        //base case1
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[pos])return false;
        //base case2
        if(pos == word.size()-1)return true;
        

        //avoid redundant traversing
        char temp = board[i][j];
        board[i][j] = '*';
        bool res = backtrack(board, word, pos+1, i + 1, j) || backtrack(board, word, pos+1, i - 1, j) ||backtrack(board, word, pos+1, i, j + 1) ||backtrack(board, word, pos+1, i, j - 1);
        board[i][j] = temp;
        return res;
    }
};