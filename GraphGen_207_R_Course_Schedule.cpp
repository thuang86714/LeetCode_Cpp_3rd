/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
*/

#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //we build a tree from prerequisites, there may be multiple trees, 
        //and the courses need no prerequisites(degree == 0)are the roots.
        //the idea is from roots, we do bfs 
        // must take course bi first if you want to take course ai.
        vector<vector<int>> graph(numCourses);//graph of trees
        vector<int> degree(numCourses, 0);
        queue<int> ZeroDegree;//tree only has root and no leaf
        for(auto p:prerequisites){
            graph[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }
        
        for(int i = 0; i < degree.size(); i++){
            if(degree[i] == 0){
                ZeroDegree.push(i);
                numCourses--;
            }
        }

        while(!ZeroDegree.empty()){
            int node = ZeroDegree.front();
            ZeroDegree.pop();

            for(auto g:graph[node]){
                int connected = g;
                degree[connected]--;
                if(degree[connected] == 0){
                    numCourses--;
                    ZeroDegree.push(connected);
                }
            }
        }
        return numCourses==0;
    }
};