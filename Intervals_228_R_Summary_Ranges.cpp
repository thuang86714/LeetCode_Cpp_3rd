#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        //edge case: nums.size() == 0
        if(nums.empty())return {};

        vector<string> result;
        int start = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i - 1]+1){
                if(start == nums[i - 1]){
                    result.push_back(to_string(start));
                }else{
                    result.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
                }
                start = nums[i];
            }
            
        }
        
        if(start == nums.back()){
            result.push_back(to_string(start));
        }else{
            result.push_back(to_string(start) + "->" + to_string(nums.back()));
        }
        return result;
    }
};