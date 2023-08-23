/*
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //sort every str in strs, then store in unordered_map
        //TC O(strs.size() + mp.size()), SC O(No. of group of anagram)
        unordered_map<string, vector<string>> mp;
        for(int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(strs[i]);
        }

        vector<vector<string>> result;

        for(auto it: mp){
            result.push_back(it.second);
        }
        return result;
    }
};