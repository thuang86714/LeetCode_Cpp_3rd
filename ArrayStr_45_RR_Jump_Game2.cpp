#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0, lastPos = 0, maxreachable = 0, i = 0;
        int n = nums.size();
        while(lastPos < n - 1){
            maxreachable = max(maxreachable, i + nums[i]);
            if(i == lastPos){
                lastPos = maxreachable;
                step++;
            }
            i++;
        }
        return step;
    }
};