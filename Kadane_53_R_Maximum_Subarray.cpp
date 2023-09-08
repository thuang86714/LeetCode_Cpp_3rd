class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_max = -10001, maxi = -10001;
        for(int i = 0; i < nums.size(); i++){
            cur_max = max(cur_max + nums[i], nums[i]);
            maxi = max(cur_max, maxi);
        }
        return maxi;
    }
};