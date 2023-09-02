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
        //sort strs, so the strs.front and strs.back would have greatest difference
        //TC O(nlogn) SC O(front.size() + back.size())
        sort(strs.begin(), strs.end());
        string front = strs.front(), back = strs.back();
        int count = 0;
        for(int i = 0; i < min(front.size(), back.size()); i++){
            if(front[i] == back[i])count++;
            else break;
        }
        return front.substr(0, count);
    }
};