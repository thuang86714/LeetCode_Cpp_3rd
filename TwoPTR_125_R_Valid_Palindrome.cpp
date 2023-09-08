#include <cctype>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        //TC O(s.size), SC O(1)
        //isalnum
        int l = 0, r = s.size()-1;
        while(l < r){
            //find the first alphabet from left side
            while(l < r && !isalnum(s[l]))l++;
            //find the first alphabet from right side
            while(l < r && !isalnum(s[r]))r--;
            //tolower to unify all alphbets into lower case
            if(tolower(s[l++]) != tolower(s[r--]))return false;
        }
        return true;
    }
};