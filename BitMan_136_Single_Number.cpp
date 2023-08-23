/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
 

Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //requirement TC O(n), SC O(1)
        //credit to Krypto2_0, solution3
        /*
        A^A=0
        A^B^A=B
        (A^A^B) = (B^A^A) = (A^B^A) = B This shows that position doesn't matter.
        Similarly , if we see , a^a^a......... (even times)=0 and a^a^a........(odd times)=a
        */
        int ans = 0;
        for(int n:nums)ans ^= n;
        return ans;
    }
};