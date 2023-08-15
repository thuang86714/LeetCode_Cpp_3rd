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
*/#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        //credit to rohit221
        stack<char> st;  //taking stack for keep tracking the order of the brackets..
        for(auto i:s)  //iterate over each and every elements
        {
            //if current element of the string will be opening bracket then we will just simply push it into the stack
            if(i=='(' or i=='{' or i=='[') st.push(i);  
            else{//this means that current element is a closing bracket, so check two conditions  1.current element matches with top of the stack and 2. the stack must not be empty...
                if(st.empty() or (st.top()=='(' and i!=')') or (st.top()=='{' and i!='}') or (st.top()=='[' and i!=']')) return false;
                st.pop();  //if control reaches to that line, it means we have got the right pair of brackets, so just pop it.
            }
        }
        //at last, it may possible that we left something into the stack unpair so return checking stack is empty or not..
        // if(s.size()%2 != 0)return false-->it would not form all pairs anyway
        return st.empty();  
    }
};