#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> visited;
        int l = 0, r = 0, size = s.size(), len = 0;
        while(r < size){
            if(!visited.count(s[r])){
                visited.insert(s[r]);
                len = max(len, r - l + 1);
                r++;
            }else{
                visited.erase(s[l]);
                l++;
            }
        }
        return len;
    }
};