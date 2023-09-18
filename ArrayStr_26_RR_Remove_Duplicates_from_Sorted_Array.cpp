#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 1, val = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[slow] = nums[i];
                slow++;
                val = nums[i];
            }
        }
        return slow;


    }
};