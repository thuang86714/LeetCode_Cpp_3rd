#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l <= r){
            int mid = (l + r)/2;
            if(nums[mid] == target)return mid;
            //finding out the local rotation status
            if(nums[l] <= nums[mid]){
                //find out the location of target
                if(target < nums[l] || target > nums[mid]){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }else{
                //find out the location of target
                if(target > nums[r] || target < nums[mid]){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
};