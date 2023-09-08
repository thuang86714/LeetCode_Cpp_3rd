#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;
        //sorting to make duplicates adjacent to each other
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            int target = -1*nums[i];
            int l = i + 1, r = nums.size()-1;
            while(l < r){
                int sum = nums[l] + nums[r];
                if(sum > target){
                    r--;
                }else if(sum < target){
                    l++;
                }else{
                    vector<int> temp = {nums[i], nums[l], nums[r]};
                    result.push_back(temp);
                    while(l < r && nums[l] == temp[1])l++;
                    while(l < r && nums[r] == temp[2])r--;
                }
            }
            while(i+1 < nums.size() && nums[i+1] == nums[i])i++;
        }
        return result;
    }
};