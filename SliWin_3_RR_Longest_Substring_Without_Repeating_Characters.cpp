#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size())return 0;
        int size = 0;
        int l = 0, r = 0, n = s.size();
        unordered_set<char>visited;
        while(l < n && r < n){
            if(!visited.count(s[r])){
                visited.insert(s[r]);
                size = max(size, r - l + 1);
                r++;
            }else{
                visited.erase(s[l]);
                l++;
            }
        }
        return size;
    }
};