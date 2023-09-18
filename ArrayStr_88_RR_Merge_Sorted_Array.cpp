#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums(m+n);
        int idx1 = 0, idx2 = 0, idx = 0;
        while(idx1 < m && idx2 < n){
            if(nums1[idx1] < nums2[idx2]){
                nums[idx] = nums1[idx1];
                idx1++;
            }else{
                nums[idx] = nums2[idx2];
                idx2++;
            }
            idx++;
        }

        while(idx1 < m){
            nums[idx] = nums1[idx1];
            idx1++;
            idx++;
        }

        while(idx2 < n){
            nums[idx] = nums2[idx2];
            idx2++;
            idx++;
        }

        nums1 = nums;
    }
};