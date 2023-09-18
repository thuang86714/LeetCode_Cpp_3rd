#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return result;
    }

    void backtrack(vector<int> nums, int idx){
        //base case
        if(idx == nums.size()){
            result.push_back(nums);
            return;
        }

        for(int i = idx; i < nums.size(); i++){
            if(i != idx && nums[i] == nums[idx])continue;
            swap(nums[idx], nums[i]);
            backtrack(nums, idx + 1);
        }
    }
};