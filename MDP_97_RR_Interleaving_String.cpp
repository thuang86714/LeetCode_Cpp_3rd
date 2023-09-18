#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        //edge case s3.size != s1.size + s2.size
        if(s3.size() != s1.size() + s2.size())return false;
        int m = s1.size(), n = s2.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        //base case
        for(int j = 1; j <= n; j++){
            dp[j] = dp[j - 1] && s3[j - 1] == s2[j - 1];  
        }

        for(int i = 1; i <= m; i++){
            dp[0] = s3[i - 1] == s1[i - 1] && dp[0];
            for(int j = 1; j <= n; j++){
                dp[j] = (s3[i + j - 1] == s1[i - 1] && dp[j]) || (s3[i + j - 1] == s2[j - 1] && dp[j - 1]);
            }
        }
        return dp.back();
    }
};