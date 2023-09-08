#include <vector>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int cur_min = 30001, cur_max = -30001, mini = 30001, maxi = -30001, total = 0;
        for(int i = 0; i < nums.size(); i++){
            cur_max = max(cur_max + nums[i], nums[i]);
            maxi = max(cur_max, maxi);
            cur_min = min(cur_min + nums[i], nums[i]);
            mini = min(cur_min, mini);
            total += nums[i];
        }
        if(maxi < 0){
            return maxi;
        }else{
            return max(maxi, total - mini);
        }

    }
};