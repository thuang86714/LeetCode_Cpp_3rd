/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size(), pre;
        vector<int> dp(n+1);
        //base case, is word1 is empty, steps taken to bacome word2
        for(int i = 1; i <= n; i++){
            dp[i] = i;
        }

        for(int j = 1; j <= m; j++){
            pre = dp[0];
            //another base case, steps taken from empty word2 to word1
            dp[0] = j;
            for(int i = 1; i <= n; i++){
                int temp = dp[i];
                if(word1[j - 1] == word2[i - 1]){
                    dp[i] = pre;
                }else{
                    dp[i] = 1 + min(pre, min(dp[i], dp[i - 1]));
                }
                pre = temp;
            }

        }
        return dp.back();
    }
};