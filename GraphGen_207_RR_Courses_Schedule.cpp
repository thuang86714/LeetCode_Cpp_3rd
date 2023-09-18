#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //topo sorting + BFS
        unordered_map<int, vector<int>>map;
        queue<int> ZeroDegree;
        vector<int> degree(numCourses);
        for(auto p:prerequisites){
            map[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }

        for(int i = 0; i < degree.size(); i++){
            if(!degree[i]){
                ZeroDegree.push(i);
                numCourses--;
            }
        }

        while(!ZeroDegree.empty()){
            int node = ZeroDegree.front();
            ZeroDegree.pop();

            for(auto connected:map[node]){
                degree[connected]--;
                if(!degree[connected]){
                    ZeroDegree.push(connected);
                    numCourses--;
                }
            }
        }
        return numCourses == 0;
    }
};