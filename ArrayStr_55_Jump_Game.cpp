/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        //TC O(n), SC O(1)
        //minJump denotes to reach the tail, the steps unfulfilled 
        int minJump = 0;
        //traverse from nums[n-2] to nums[0]
        for(int i = nums.size()-2; i >= 0; i--){
            minJump++;//traverse from nums[n-2], nit nums[n-1]
            if(nums[i] >= minJump)minJump = 0;
        }
        return minJump == 0;
    }
};