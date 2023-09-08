#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //TC O(n^3)
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        for(int i = 0; i < nums.size(); i++){
            long long int target1 = target - nums[i];
            for(int j = i + 1; j < nums.size(); j++){
                long long int target2 = target1 - nums[j];
                int l = j + 1, r = nums.size()-1;
                while(l < r){
                    long long int sum = nums[l] + nums[r];
                    if(sum > target2){
                        r--;
                    }else if(sum < target2){
                        l++;
                    }else{
                        vector<int> temp = {nums[i], nums[j], nums[l], nums[r]};
                        result.push_back(temp);

                        while(l < r && temp[2] == nums[l])l++;
                        while(l < r && temp[3] == nums[r])r--;
                    }
                }
                while(j + 1 < nums.size() && nums[j + 1] == nums[j])j++;
            }
            while(i + 1 < nums.size() && nums[i + 1] == nums[i])i++;
        }
        return result;
    }
};