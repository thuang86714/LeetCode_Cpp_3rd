/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/

#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //given t.length == s.length
        //using unordered_map to doing char mapping
        //TC O(size), SC O(size) 
        unordered_map<char, char> mp1, mp2;
        int size = s.size();
        for(int i = 0; i < size; i++){
            if(mp1.find(s[i]) == mp1.end() && mp2.find(t[i]) == mp2.end()){
                //if(mp[s[i]] != t[i])return false;
                mp1[s[i]] = t[i];
                mp2[t[i]] = s[i];
            }else{
                if(mp1[s[i]] != t[i] || mp2[t[i]] != s[i])return false;
            }
        }
        return true;
    }
};