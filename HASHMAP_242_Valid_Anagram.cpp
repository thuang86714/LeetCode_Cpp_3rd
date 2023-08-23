/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        //TC O(s.size()), SC O(s.size())
        //edge case s.size() != t.size()
        if(s.size() != t.size())return false;
        unordered_map<char, int> count;
        for(int i= 0; i < s.size(); i++){
            count[s[i]]++;
            count[t[i]]--;
        }
        for(auto c: count){
            if(c.second != 0)return false;
        }
        return true;
    }
};