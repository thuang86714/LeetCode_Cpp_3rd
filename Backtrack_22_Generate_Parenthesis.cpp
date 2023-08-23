/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string temp ="";
        recur(0, 0, n, result, temp);
        return result;
    }

    //open-->num of '(', close -->num of ')'
    void recur(int open, int close, int n, vector<string>& result, string temp){
        //base case
        if(open == n && close ==n){
            result.push_back(temp);
            return;
        }

        //not if else, two consecutive if
        //both could happen
        if(open < n){
            recur(open+1, close, n, result, temp+'(');
        }
        if(open > close){
            recur(open, close+1, n, result, temp + ')');
        }
    }
};