#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> dp(n + 1, 0);
        //base case, from empty word1 become word2
        for(int j = 1; j <= n; j++){
            dp[j] = j;
        }

        int pre;
        for(int i = 1; i <= m; i++){
            pre = dp[0];
            dp[0] = i;
            for(int j = 1; j <= n; j++){
                int temp = dp[j];
                if(word1[i - 1] == word2[j - 1]){
                    dp[j] = pre;
                }else{
                    dp[j] = 1 + min(pre, min(dp[j], dp[j - 1]));
                }
                pre = temp;
            }
        }
        return dp.back();
    }
};