#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        //edge case s.size != t.size()
        if(s.size() != t.size())return false;
        //<char, count>
        unordered_map<char, int>map;
        for(char c:s){
            map[c]++;
        }
        for(char c:t){
            map[c]--;
        }

        for(auto m:map){
            if(m.second < 0)return false;
        }
        return true;
    }
};