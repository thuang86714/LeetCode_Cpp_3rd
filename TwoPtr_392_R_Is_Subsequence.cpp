#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        //TC O(t.size()), SC O(1)
        //we are looking for a subsequence, not subarray
        int len = s.size(), count = s.size();
        for(int i = 0; i < t.size(); i++){
            if(t[i] == s[len - count])count--;
        }
        return count == 0;
    }
};