/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.
*/
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //TC O(m+n), SC O(m)
        unordered_map<char, int> map;
        for(char c:magazine){
            map[c]++;
        }
        for(char c: ransomNote){
            map[c]--;
            if(map[c] < 0)return false;
        }
        return true;
    }
};