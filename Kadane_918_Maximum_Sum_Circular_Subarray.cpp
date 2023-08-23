/*
Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
Example 3:

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.
 

Constraints:

n == nums.length
1 <= n <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        /*
        TC O(n), SC O(1)
        credit to lee215
        So there are two case.
        Case 1. The first is that the subarray take only a middle part, and we know how to          find the max subarray sum.
        Case2. The second is that the subarray take a part of head array and a part of tail     array.
        We can transfer this case to the first one.
        The maximum result equals to the total sum minus the minimum subarray sum.

        for edge case:
        Just one to pay attention:
        If all numbers are negative, maxSum = max(A) and minSum = sum(A).
        In this case, max(maxSum, total - minSum) = 0, which means the sum of an empty      subarray.
        According to the deacription, We need to return the max(A), instead of sum of am empty   subarray.
        So we return the maxSum to handle this corner case.
        */
        int total = 0, maxSum = nums[0], curMax = 0, minSum = nums[0], curMin = 0;
        for(int n:nums){
            curMax = max(curMax+n, n);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin+n, n);
            minSum = min(minSum, curMin);
            total += n;
        }
        //edge case: all elements in nums are negative
        if(maxSum < 0){
            return maxSum;
        }else{
            //max(case1, case2)
            return max(maxSum, total - minSum);
        }
    }
};