/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //to make the duplicates adjacent
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        for(int i = 0; i < nums.size(); i++){
            //nums[i] + nums[j] + nums[k] = 0
            int target = -1*nums[i];
            int front = i + 1, back = nums.size()-1;
            while(front < back){
                if(nums[front] + nums[back] > target)back--;
                else if(nums[front] + nums[back] < target)front++;
                else{
                    vector<int> temp = {nums[i], nums[front], nums[back]};
                    result.push_back(temp);

                    //to handle duplicate of temp[1] and temp[2]
                    while(front < back && temp[1] == nums[front])front++;
                    while(front < back && temp[2] == nums[back])back--;
                }
            }
            //to handle the duplicate of temp[0]
            while(i+1 < nums.size() && nums[i+1] == nums[i])i++;

        }
        return result;
    }
};