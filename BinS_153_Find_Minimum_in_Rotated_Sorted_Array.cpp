/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
 

Constraints:

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
All the integers of nums are unique.
nums is sorted and rotated between 1 and n times.

*/

#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        //solution credit goes to changhaz
        /*
        Q: when do you use while (start<end) , when do you use while (start<=end)?
        credit to studyhardeveryday
        1.You use while (start <= end) if you are returning the match from inside the loop.
        2.You use while (start < end) if you want to exit out of the loop first, and then use the result of start or end to return the match.
        */
        int l = 0, r = nums.size()-1;
        
        //doing Binary search
        while(l < r){
            int mid = (l + r)/2;
            //If the array is already sorted then return first element
            if(nums[l] < nums[r])return nums[l];
            //If the nums[mid] is in the right hand side, then it must be no greater than the smallest number in the left hand side
            if(nums[l] > nums[mid])r = mid;
            //If the nums[mid] is in the left hand side, then it must be greater than the smallest number in the left hand side
            else l = mid + 1;
        }
        return nums[l];
    }
};