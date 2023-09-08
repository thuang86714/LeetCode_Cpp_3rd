#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int r = 0, l = 0;
        vector<string> strs;
        string temp; 
        unordered_map<char, string> map1;
        unordered_map<string, char> map2;

        for(int i = 0; i < s.size(); i++){
            if(isalnum(s[i])){
                temp += s[i];
            }else{
                strs.push_back(temp);
                temp = "";
            }
        }
        if(temp.size())strs.push_back(temp);

        if(pattern.size() != strs.size())return false;

        for(int i = 0; i < pattern.size(); i++){
            if(map1.find(pattern[i]) == map1.end() && map2.find(strs[i]) == map2.end()){
                map1[pattern[i]] = strs[i];
                map2[strs[i]] = pattern[i];
            }else{
                if(map1[pattern[i]] != strs[i] || map2[strs[i]] != pattern[i])return false;
            }
        }
        return true;
    }
};