#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //<val, pos>
        unordered_map<int, int>map;
        for(int i = 0; i < nums.size(); i++){
            if(map.find(target - nums[i]) == map.end()){
                map[nums[i]] = i;
            }else{
                return {map[target - nums[i]], i};
            }
        }
        return {};
    }
};