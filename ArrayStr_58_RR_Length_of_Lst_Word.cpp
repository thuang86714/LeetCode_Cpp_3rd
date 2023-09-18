#include <algorithm>
#include <string>
using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(!isalnum(s[i]) && !count)continue;
            if(isalnum(s[i]))count++;
            if(!isalnum(s[i]) && count)break;
        }
        return count;
    }
};