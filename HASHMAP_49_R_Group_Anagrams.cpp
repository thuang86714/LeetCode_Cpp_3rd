#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>map;
        for(string s:strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            map[temp].push_back(s);
        }
        vector<vector<string>> result;
        for(auto m:map){
            result.push_back(m.second);
        }
        return result;

    }
};