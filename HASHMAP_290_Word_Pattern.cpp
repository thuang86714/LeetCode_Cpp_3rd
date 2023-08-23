/*
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
 

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.
*/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        //TC O(pattern.size() + s.word_size()), SC O(pattern.size() + s.word_size())
        unordered_map<char, string> mp;
        unordered_map<string, char> mp2;
        vector<string> temp;
        string word;
        for(int i = 0; i < s.size(); i++){
            //check if not space, then store into the temp vector, with the same order
            if(isalnum(s[i])){
                word += s[i];
            }else{
                //no leading or trailing space
                temp.push_back(word);
                word = "";
            }
        }
        //dont forget the last word in s
        if(word.size())temp.push_back(word);
        
        //if the len of pattern != No. of word, there's no way to have a match
        if(pattern.size() != temp.size())return false;

        for(int i = 0; i < pattern.size(); i++){
            //if the char in pattern match to the same string, and also the other way around
            if(mp.find(pattern[i]) == mp.end() && mp2.find(temp[i]) == mp2.end()){
                mp[pattern[i]] = temp[i];
                mp2[temp[i]] = pattern[i];
            }else{
                if(mp[pattern[i]] != temp[i] || mp2[temp[i]] != pattern[i])return false;
            }
        }
        return true;
    }
};