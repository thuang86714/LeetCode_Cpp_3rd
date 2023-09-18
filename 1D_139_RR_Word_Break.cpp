#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> Dict;
        for(string s:wordDict){
            Dict.insert(s);
        }
        int size = s.size();
        vector<bool> dp(size + 1, false);

        dp[0] = true;
        for(int i = 1; i <= size; i++){
            for(int j = i - 1; j >= 0; j--){
                if(Dict.count(s.substr(j, i - j)) && dp[j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};