#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1)return s;
        vector<string> temp(numRows, "");
        int j = 0, dir = -1;
        for(int i = 0; i < s.size(); i++){
            if(j == numRows - 1 || j == 0)dir *= -1;

            temp[j] += s[i];

            if(dir == 1)j++;
            else j--; 
        }
        string result;
        for(string s:temp)result += s;
        return result;
    }
};