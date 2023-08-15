/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 

Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //1 <= nums.length <= 105-->min starting val = 10^5 +1
        int slow = 0, fast = 0, n = nums.size(), len = 100000+1, sum = 0;
        //edge case: nums.sum() < target-->return 0
        while(fast < n){
            sum += nums[fast++];
            while(sum >= target){
                //not fast - slow +1 because fast already ++
                len = min(len, fast - slow);
                sum -= nums[slow++];
            }
        }
        if(len == 100000 + 1)return 0;
        else return len;
    }
};

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        //credit to jianchao li
        //TC O(nlogn) SC O(n)
        int n = nums.size(), len = INT_MAX;
        vector<int> sums(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = n; i >= 0 && sums[i] >= s; i--) {
            int j = upper_bound(sums.begin(), sums.end(), sums[i] - s) - sums.begin();
            len = min(len, i - j + 1);
        }
        return len == INT_MAX ? 0 : len;
    }
};