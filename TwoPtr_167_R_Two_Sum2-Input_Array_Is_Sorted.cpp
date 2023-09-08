#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //TC O(n), SC O(1)
        int l = 0, r = numbers.size()-1;
        while(l < r){
            int sum = numbers[l] + numbers[r];
            if(sum == target){
                return {l+1, r+1};
            }else if(sum < target){
                l++;
            }else{
                r--;
            }
        }
        return {};
    }
};