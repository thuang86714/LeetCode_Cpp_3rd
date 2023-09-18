#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        backtrack(candidates, target, temp, 0);
        return result;
    }

    void backtrack(vector<int>& nums, int target, vector<int>& temp, int idx){
        //base case
        if(target < 0)return;
        if(target == 0){
            result.push_back(temp);
            return;
        }

        for(int i = idx; i < nums.size(); i++){
            temp.push_back(nums[i]);
            backtrack(nums, target - nums[i], temp, i);
            temp.pop_back();
        }
    }
};