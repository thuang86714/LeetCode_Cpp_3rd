#include <vector>
using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //credit to kshatriyas, sol2
        int ans = 0;
        for(int i = 0; i < 32; i++){
            int sum = 0;
            for(int n:nums){
                sum += (n>>i)&1;
            }
            sum %= 3;
            ans |= sum<<i;
        }
        return ans;
    }
};