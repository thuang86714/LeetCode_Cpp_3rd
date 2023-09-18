#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        //return l
        int l = 0, r = nums.size()-1;
        while(l < r){
            int mid = (l + r)/2;
            //find out how the array is rotated
            //there's no rotation
            if(nums[l] < nums[r])return nums[l];
            if(nums[mid] >= nums[l]){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return nums[l];
    }
};