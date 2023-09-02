/*
You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.

 

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
note: x is undefined => -1.0
Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]
Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]
 

Constraints:

1 <= equations.length <= 20
equations[i].length == 2
1 <= Ai.length, Bi.length <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= Cj.length, Dj.length <= 5
Ai, Bi, Cj, Dj consist of lower case English letters and digits.
*/
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //a map to store<src, vector of all dst and it's val>
    unordered_map<string, vector<pair<string, double>>>map;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //core idea src/dst = src/x * x/dst
        vector<double> result;

        //push all known src/dst pair into map
        for(int i = 0; i < equations.size(); i++){
            string a = equations[i][0];
            string b = equations[i][1];

            double val = values[i];
            map[a].push_back({b, val});
            map[b].push_back({a, 1/val});
        }

        //for every queries do dfs on map to see if there's a match
        for(auto q: queries){
            unordered_set<string> visited;
            result.push_back(dfs(q[0], q[1], visited));
        }
        return result;
    }
private:
    double dfs(string src, string dst, unordered_set<string> visited){
        //base case
        if(map.find(src) == map.end())return -1;
        if(src == dst)return 1;

        for(auto node: map[src]){
            //avoid redundant traversing
            if(visited.count(node.first))continue;
            visited.insert(node.first);
            double res = dfs(node.first, dst, visited);
            if(res != -1)return res*node.second;
        }
        return -1;


    }
};