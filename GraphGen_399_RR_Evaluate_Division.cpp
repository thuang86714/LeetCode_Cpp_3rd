#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<double> res;
    unordered_map<string, vector<pair<string, double>>>graph;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //core idea: x/y = x/k * k/y
        
        for(int i = 0; i < equations.size(); i++){
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            graph[a].push_back({b, val});
            graph[b].push_back({a, 1/val});
        }
        unordered_set<string>visited;//avoid redandunt traversing
        for(auto q:queries){
            res.push_back(recur(q[0], q[1], visited));
        }
        return res;
    }

    double recur(string src, string dst, unordered_set<string> visited){
        //base case
        if(graph.find(src) == graph.end() || graph.find(dst) == graph.end())return -1;
        if(src == dst)return 1;

        for(auto next:graph[src]){
            string temp = next.first;
            if(visited.count(temp))continue;
            visited.insert(temp);
            double res = recur(temp, dst, visited);
            if(res != -1)return res*next.second;
        }
        return -1;

    }
};