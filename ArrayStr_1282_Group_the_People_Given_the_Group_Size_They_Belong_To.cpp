#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        int n = groupSizes.size();
        vector<vector<int>> temp(n+1);
        vector<vector<int>> result;
        for(int i = 0; i < n; i++){
            temp[groupSizes[i]].push_back(i);
            if(temp[groupSizes[i]].size() == groupSizes[i]){
                result.push_back(temp[groupSizes[i]]);
                temp[groupSizes[i]].clear();
            }
        }
        return result;
    }
};