/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //TC O(n) , SC O(n)
        //TC not O(n^2) because only when if(map[nums[i]] == true){
        //would the nested while loop take place
        unordered_map<int, bool> map;
        for(int i = 0; i<nums.size(); i++){
            map[nums[i]] = true;
        }
        //set map[nums[i]] to true only if it's the head of the sequence
        for(int i=0; i<nums.size(); i++){
            if(map.count(nums[i]-1) > 0){
                map[nums[i]] = false;
            }
        }
        int maxlen = 0;
        for(int i=0; i<nums.size(); i++){
            if(map[nums[i]] == true){
                int j=0; int count=0;
                while(map.count(nums[i]+j) > 0){
                    j++;
                    count++;
                }
                maxlen = max(count, maxlen);
            }
        }
        return maxlen;
    }
};
