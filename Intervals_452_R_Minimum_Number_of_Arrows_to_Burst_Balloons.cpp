#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int count = 1;
        int lastpoint = points[0][1];
        for(int i = 0; i < points.size(); i++){
            if(lastpoint < points[i][0]){
                count++;
                lastpoint = points[i][1];
            }
            lastpoint = min(lastpoint, points[i][1]);
        }

        return count;
    }
};