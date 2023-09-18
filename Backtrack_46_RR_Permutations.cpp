#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }

    void backtrack(vector<int>& nums,int idx){
        //base case
        if(idx == nums.size()){
            result.push_back(nums);
            return;
        }

        for(int i = idx; i < nums.size(); i++){
            swap(nums[i], nums[idx]);
            backtrack(nums, idx+1);
            swap(nums[i], nums[idx]);
        }
    }
};