#include <vector>
#include <algorithm>
using namespace std;



class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        for(int i = 0; i < nums.size(); i++){
            if(temp.empty() || temp.back() < nums[i]){
                temp.push_back(nums[i]);
            }else{
                *lower_bound(temp.begin(), temp.end(), nums[i]) = nums[i];
            }
        }
        return temp.size();
    }
};