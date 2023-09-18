#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string res = "";
        string front = strs.front(), back = strs.back();
        for(int i = 0; i < min(front.size(), back.size()); i++){
            if(front[i] == back[i]){
                res += front[i];
            }else{
                break;
            }
        }
        return res;
    }
};