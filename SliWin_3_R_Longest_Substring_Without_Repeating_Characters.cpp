#include <unordered_set>
#include <string>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int slow = 0, fast = 0, len = INT_MIN, n = s.size();
        if(!n)return 0;
        unordered_set<int> visited;
        while(fast < n && slow < n){
            if(!visited.count(s[fast])){
                visited.insert(s[fast]);
                len = max(len, fast - slow + 1);
                fast++;
            }else{
                visited.erase(s[slow]);
                slow++;
            }
        }
        return len;
    }
};