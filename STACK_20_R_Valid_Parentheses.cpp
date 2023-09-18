/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        //LIFO
        //TC O(n), SC O(n)
        stack<char> st;
        for(char c:s){
            if(c == '(' || c == '{' || c == '[')st.push(c);
            else{
                if((st.empty()) || st.top() == '(' && c != ')' || st.top() == '{' && c != '}' || st.top() == '[' && c != ']')return false;
                st.pop();
            }
        }

        //if st.empty() != true, meaning there's ( || { || [ remains unpaired in the stack
        return st.empty();
    }
};