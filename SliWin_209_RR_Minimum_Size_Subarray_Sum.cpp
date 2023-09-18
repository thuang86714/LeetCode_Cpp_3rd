#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums.size() == 1){
            if(nums[0] < target)return 0;
            else return 1;
        }

    	int size = 100001, sum = 0;
        int l = 0, r = 0, n = nums.size();
        while(r < n){
            sum += nums[r++];
            while(sum >= target){
                size = min(size, r - l);
                sum -= nums[l];
                l++;
            }
        }
        if(size == 100001){
            return 0;
        }else{
            return size;
        }
        
    }
};