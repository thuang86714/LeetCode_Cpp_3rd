/*
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        //TC O(n^2), sc O(n)
        //intuition 1d dp
        int n = nums.size();
        //1 <= nums.length <= 10^4 --> init val is 10001
        vector<int> dp(n, 10001);
        dp[n - 1] = 0;
        for(int i = n - 2; i >= 0; i--){
            for(int jumpLen = 1; jumpLen <= nums[i]; jumpLen++){
                dp[i] = min(dp[i], 1 + dp[(min(n - 1, i + jumpLen))]);
            }
        }
        return dp[0];
    }
};

class Solution {
public:
    int jump(vector<int>& nums) {
        //credit to archit91
        //greedy
        int n = nums.size(), i = 0, maxReachable = 0, lastPos = 0, jump = 0;
        while(lastPos < n - 1){//not jumping out of range
            // furthest index reachable in the next jump from current jump
            maxReachable = max(maxReachable, i + nums[i]);
            if(i == lastPos){// current level has been iterated & maxReachable position on next level has been finalised
                lastPos = maxReachable;// so just move to that maxReachable position
                jump++;
        // NOTE: jump^ only gets updated after we iterate all possible jumps from previous level
	    //This ensures jumps will only store minimum jump required to reach lastJumpedPos
            }
            i++;
        }
        return jump;
    }
};