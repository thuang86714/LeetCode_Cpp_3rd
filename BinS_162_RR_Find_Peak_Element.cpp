#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //looking for local maximum-->the peak of a rising slope
        int l = 0, r = nums.size()-1;
        while(l < r){
            int mid1 = (l + r)/2;
            int mid2 = mid1 + 1;
            //we've found a rising slope
            if(nums[mid2] > nums[mid1])l = mid2;
            else r = mid1;
        }
        return r;
    }
};