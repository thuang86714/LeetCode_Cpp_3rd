#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //<char, count>
        unordered_map<char, int>map;
        for(char c: magazine){
            map[c]++;
        }

        for(char c:ransomNote){
            map[c]--;
        }

        for(auto m:map){
            if(m.second < 0)return false;
        }
        return true;
    }
};