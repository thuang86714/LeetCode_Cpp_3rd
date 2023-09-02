/*
Given an integer array nums, return the length of the longest strictly increasing 
subsequence
.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
 

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?

*/



#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //TC O(n^2), SC O(n)
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j] && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

//O(n log(n)) time complexity

#include <algorithm>
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //credit to hiepit
        //to the followup question
        //TC O(nlogn)-->Binary search by the lower_bound
        vector<int> temp;
        for(int n:nums){
            if(temp.empty() || temp.back() < n)temp.push_back(n);
            else{
                // Find the index of the first element >= x
                auto it = lower_bound(temp.begin(), temp.end(), n);
                // Replace that number with x
                *it = n;
            }
        }
        return temp.size();
    }
};