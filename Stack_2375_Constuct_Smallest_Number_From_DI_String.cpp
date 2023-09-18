#include <string>
using namespace std;

class Solution {
public:
    string smallestNumber(string pattern) {
        //credit to lee215, TC O(n), SC O(n)
        string num, st;
        for(int i = 0; i <= pattern.size(); i++){
            st.push_back('1' + i);
            if(i == pattern.size() || pattern[i] == 'I'){
                while(!st.empty()){
                    num.push_back(st.back());
                    st.pop_back();
                }
            }
        }
        return num;

    }
};