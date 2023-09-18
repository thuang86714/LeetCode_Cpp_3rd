#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //TC O(n), SC O(1)
        //cannot do sorting, or unordered_map
        //+ or *?
        //edge case nums.size() == 2
        //credit to lchen77

        //basic idea is x^y^y = x
        long int aXorb = 0;
        for(int n:nums){
            aXorb ^= n;
        }
        // the last bit that a diffs b
        long int lastbit = (aXorb & (aXorb-1))^ aXorb;
        int a = 0, b = 0;
        for(int n:nums){
            if(n & lastbit){
                a ^= n;
            }else{
                b ^= n;
            }
        }
        return {a, b};
    }
};