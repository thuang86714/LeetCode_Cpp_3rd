#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int l = 0, r = nums.size()-1;
        //first while loop to find the starting pos
        while(l <= r){
            int mid = (l + r)/2;
            if(nums[mid] < target){
                l = mid + 1;
            }else{
                if(nums[mid] == target)res[0] = mid;
                r = mid -1;
            }
        }
        //reset
        l = 0, r = nums.size()-1;
        //second while loop to find the ending pos
        while(l <= r){
            int mid = (l + r)/2;
            if(nums[mid] > target){
                r = mid - 1;
            }else{
                if(nums[mid] == target)res[1] = mid;
                l = mid + 1;
            }
        }

        return res;
    }
};