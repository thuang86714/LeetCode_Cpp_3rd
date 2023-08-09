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
class Solution {
public:
    int minDistance(string word1, string word2) {
        //credit to jianchao-li
        //TC O(m*n), SC O(2n)
        /*
        If word1[i - 1] != word2[j - 1], we need to consider three cases.
        1. Replace word1[i - 1] by word2[j - 1] (dp[i][j] = dp[i - 1][j - 1] + 1);
        2. If word1[0..i - 1) = word2[0..j) then delete word1[i - 1] (dp[i][j] = dp[i - 1][j] + 1);
        3. If word1[0..i) + word2[j - 1] = word2[0..j) then insert word2[j - 1] to word1[0..i) (dp[i][j] = dp[i][j - 1] + 1).
        
        */
        int m = word1.size();
        int n = word2.size();
        vector<int> cur(n+1), pre(n+1);

        /*
        For the base case, that is, to convert a string to an empty string, the mininum number of operations (deletions) is just the length of the string. So we have dp[i][0] = i and dp[0][j] = j.
        */
        for(int j = 1; j <= n; j++){
            pre[j] = j;
        }

        for(int i = 1; i <= m; i++){
            cur[0] = i;
            for(int j = 1; j <= n; j++){
                //if word1[i - 1] == word2[j - 1], then no more operation is needed and dp[i][j] = dp[i - 1][j - 1].
                if(word1[i - 1] == word2[j - 1]){
                    cur[j] = pre[j - 1];
                }else{
                    cur[j] = min(pre[j - 1], min(cur[j - 1], pre[j])) + 1;
                }
            }
            fill(pre.begin(), pre.end(), 0);
            swap(pre, cur);
        }
        return pre[n];
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size(), pre;
        //TC O(m*n), SC O(n)
        vector<int> cur(n+1);

        /*
        for each iteration of inner for loop
            pre    | cur[j]
        -----------|--------------------
        cur[j - 1] | what we are handling
        */


        //base case, meaning if word1 is empty, total steps require to become word2.substr(0, j)
        for(int j = 1; j <= n; j++){
            cur[j] = j;
        }

        //traverse all chars in boths words
        for(int i = 1; i <= m ; i++){
            pre = cur[0];
            cur[0] = i;//another base case, meaning from word1 to become word2.substr(0, 0)
            for(int j = 1; j <= n; j++){
                int temp = cur[j];
                if(word1[i - 1] == word2[j - 1]){
                    cur[j] = pre;
                }else{
                    /*
                    there are 3 actions available in this case
                    Replace
                    Insert
                    Remove
                    choose the minimum
                    */
                    /*
                    in SC O(m*n), 
                        dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
                    in SC O(2n),
                        cur[j] = 1 + min(pre[j - 1], min(pre[j], cur[j - 1]));
                    */
                    cur[j] = 1 + min(pre, min(cur[j], cur[j - 1]));
                }
                pre = temp;
            }
        }
        return cur[n];
    }
};