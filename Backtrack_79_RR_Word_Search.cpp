#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        //TC O(logm*n), SC O(logm*n)
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(recur(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }

    bool recur(vector<vector<char>>& board, string word, int i, int j, int pos){
        //base case
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[pos])return false;
        //base case
        if(pos == word.size() - 1)return true;
        //avoid redundant traversing
        char temp = board[i][j];
        board[i][j] = '*';
        bool result = recur(board, word, i + 1, j, pos +1) || recur(board, word, i - 1, j, pos +1) || recur(board, word, i, j + 1, pos +1) || recur(board, word, i, j - 1, pos +1); 
        board[i][j] = temp;
        return result;
    }
};