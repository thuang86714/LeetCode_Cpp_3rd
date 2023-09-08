#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sort by the first num in each vector
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;

        result.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++){
            if(result.back()[1] < intervals[i][0]){
                result.push_back(intervals[i]);
            }else{
                if(result.back()[1] < intervals[i][1]){
                    result.back()[1] = intervals[i][1];
                }
            }
        }

        return result;
    }
};