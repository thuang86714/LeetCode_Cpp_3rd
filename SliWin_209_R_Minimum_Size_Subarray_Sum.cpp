#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums.size() == 1){
            if(nums[0] >= target)return true;
            else return false;
        }

        int l = 0, r = 0, sum = 0, count = 100001;
        while(r < nums.size()){
            sum += nums[r++];
            while(sum >= target){
                count = min(count, r - l);
                sum -= nums[l];
                l++;
            }
        }
        if(count == 100001){
            return 0;
        }else{
            return count;
        }
    }
};