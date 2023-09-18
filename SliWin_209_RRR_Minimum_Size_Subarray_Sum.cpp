#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, sum = 0, len = 100001, n = nums.size();
        while(r < n){
            sum += nums[r];

            while(sum >= target){
                len = min(len, r - l + 1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        if(len == 100001){
            return 0;
        }else{
            return len;
        }

    }
};