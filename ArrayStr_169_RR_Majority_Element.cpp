#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size()-1, mid = (l + r)/2;
        return nums[mid];
    }
};