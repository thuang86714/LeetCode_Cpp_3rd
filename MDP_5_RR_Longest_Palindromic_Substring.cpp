#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if(!size)return "";
        vector<vector<bool>> dp(size, vector<bool> (size));

        for(int i = 0; i < size; i++){
            dp[i][i] = true;
        }

        string result = "";
        result += s[0];
        for(int i = size -1; i >= 0; i--){
            for(int j = i + 1; j < size; j++){
                if(s[i] == s[j]){
                    if(j - i == 1|| dp[i + 1][j - 1]){
                        dp[i][j] = true;
                        if(result.size() < j - i + 1){
                            result = s.substr(i, j - i + 1);
                        }
                    }
                }
            }
        }
        return result;
    }
};