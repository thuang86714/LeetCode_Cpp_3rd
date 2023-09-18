#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //set.emplace.second
        vector<unordered_set<int>> row(9), col(9), sqr(9);
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int k = i/3*3 + j/3;

                    if(!row[i].emplace(board[i][j]).second)return false;
                    if(!col[j].emplace(board[i][j]).second)return false;
                    if(!sqr[k].emplace(board[i][j]).second)return false;
                }
            }
        }
        return true;
    }
};