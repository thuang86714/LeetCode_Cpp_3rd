#include <unordered_map>
#include <string>
using namespace std;


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //<char from s, char from t>
        unordered_map<char, char>map1;
        //<char from t, char from s>
        unordered_map<char, char>map2;

        for(int i = 0; i < s.size(); i++){
            if(map1.find(s[i]) != map1.end() && map2.find(t[i]) != map2.end()){
                if(map1[s[i]] != t[i] || map2[t[i]] != s[i])return false;
            }else if(map1.find(s[i]) == map1.end() && map2.find(t[i]) == map2.end()){
                map1[s[i]] = t[i];
                map2[t[i]] = s[i];
            }else{
                return false;
            }
        }
        return true;
    }
};