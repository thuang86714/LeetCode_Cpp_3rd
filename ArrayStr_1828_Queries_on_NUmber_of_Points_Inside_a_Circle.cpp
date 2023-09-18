#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        //TC O(p*q) where p is points.size(), q is queries.size()
        vector<int> result;
        for(auto q:queries){
            int count = 0;
            for(auto p:points){
                int x_sqr = (q[0] - p[0])*(q[0] - p[0]);
                int y_sqr = (q[1] - p[1])*(q[1] - p[1]);
                if(q[2]*q[2] >= x_sqr + y_sqr)count++;
            }
            result.push_back(count);
        }
        return result;
    }
};