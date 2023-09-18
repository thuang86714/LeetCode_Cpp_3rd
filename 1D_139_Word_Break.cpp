/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 

Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
*/
#include <string>
#include <unordered_set>
#include <vector>
 using namespace std;
 
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //Note that the same word in the dictionary may be reused multiple times in the segmentation.
        //brute force nested loop to see if a match in dict, along with dp<bool>
        //edge case: s is shorter than the shortest word in dict
        //TC O(n^2), SC O(n)
        int len = s.size();
        
        //we need to leverage set.find()
        unordered_set<string> dict;
        for(string s: wordDict)dict.insert(s);

        vector<bool> dp(len+1, false);
        dp[0] = true;//base case
        for(int i = 1; i <= len; i++){
            for(int j = i - 1; j >= 0; j--){
                if(dp[j] && dict.find(s.substr(j, i - j)) != dict.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};