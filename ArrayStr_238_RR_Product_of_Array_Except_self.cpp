#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        int prefix = 1, postfix = 1;
        for(int i = 0; i < nums.size(); i++){
            res[i] = prefix;
            prefix *= nums[i];
        }

        for(int i = nums.size()-1; i >= 0; i--){
            res[i] *= postfix;
            postfix *= nums[i];
        }   
        return res;
    }
};