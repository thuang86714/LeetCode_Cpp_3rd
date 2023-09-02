/*
Given a string s, return the longest 
palindromic
 
substring
 in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        //TC O(n^2) SC O(n^2)
        int size = s.size();
        if(!size)return "";
        vector<vector<bool>> dp(size, vector<bool>(size, false));
        //base case
        for(int i = 0; i < size; i++){
            dp[i][i] = true;
        }

        string result = "";
        result += s[0];//in case size ==1
        for(int i = size -1; i >= 0; i--){
            for(int j = i +1; j < size; j++){
                if(s[i] == s[j]){
                    if(j - i == 1 || dp[i + 1][j - 1]){
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
