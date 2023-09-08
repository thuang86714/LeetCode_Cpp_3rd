class Solution {
public:
    vector<string> result;
    vector<string> keyboard = {{""}, {""}, {"abc"}, {"def"}, {"ghi"}, {"jkl"}, {"mno"}, {"pqrs"}, {"tuv"}, {"wxyz"}};
    vector<string> letterCombinations(string digits) {
        //TC O(3^n), SC O(logn), n is digits.size()
        if(digits.size() == 0)return {};
        string temp = "";
        backtrack(digits, 0, temp);
        return result;
    }

    void backtrack(string digits, int idx, string& temp){
        //base case
        if(idx >= digits.size()){
            result.push_back(temp);
            return;
        }

        for(char c: keyboard[digits[idx] - '0']){
            temp += c;
            backtrack(digits, idx+1, temp);
            int size = temp.size();
            temp = temp.substr(0, size-1);
        }
    }
};

class Solution {
public:
    vector<string> result;
    vector<string> keyboard = {{""}, {""}, {"abc"}, {"def"}, {"ghi"}, {"jkl"}, {"mno"}, {"pqrs"}, {"tuv"}, {"wxyz"}};
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)return {};
        string temp = "";
        backtrack(digits, 0, temp);
        return result;
    }

    void backtrack(string digits, int idx, string temp){
        //base case
        if(idx >= digits.size()){
            result.push_back(temp);
            return;
        }

        for(char c: keyboard[digits[idx] - '0']){
            backtrack(digits, idx+1, temp + c);
        }
    }
};