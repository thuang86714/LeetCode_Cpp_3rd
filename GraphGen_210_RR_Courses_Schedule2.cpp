#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>>map;
        queue<int> ZeroDegree;
        vector<int> degree(numCourses);
        vector<int> res;
        for(auto p:prerequisites){
            map[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }

        for(int i = 0; i < degree.size(); i++){
            if(!degree[i]){
                ZeroDegree.push(i);
                numCourses--;
                res.push_back(i);
            }
        }
        
        while(!ZeroDegree.empty()){
            int node = ZeroDegree.front();
            ZeroDegree.pop();

            for(auto connected:map[node]){
                degree[connected]--;
                if(!degree[connected]){
                    ZeroDegree.push(connected);
                    res.push_back(connected);
                    numCourses--;
                }
            }
        }
        if(numCourses == 0){
            return res;
        }else{
            return {};
        }
    }
};