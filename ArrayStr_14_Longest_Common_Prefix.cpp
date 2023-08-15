/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //using sorting to let the most similar words to be adjacent to one another
        sort(strs.begin(), strs.end());
        //the greatest variance would be between first and the last word in the vector
        string first = strs.front(), last = strs.back();
        string result;
        for(int i = 0; i < min(first.size(), last.size()); i++){
            if(first[i] != last[i])return result;
            result += first[i];
        }
        return result;
    }
};