#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    vector<string> keyboard = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<string> result;
    vector<string> letterCombinations(string digits) {
        //TC O(3^N × 4^M), SC O(3^N × 4^M)
        if(!digits.size())return {};
        string temp = "";
        backtrack(digits, temp, 0);
        return result;
    }

    void backtrack(string digits, string& temp, int idx){
        //base case
        if(idx >= digits.size()){
            result.push_back(temp);
            return;
        }

        for(char c: keyboard[digits[idx] - '0']){
            temp += c;
            backtrack(digits, temp, idx+1);
            temp.pop_back();
        }
    }
};