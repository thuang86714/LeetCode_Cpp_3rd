/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //TC O(nlogn), SC O(1)
        //do sorting(by intervals[i][0]) to make sure result[0][0] is correct
        sort(intervals.begin(), intervals.end());// O(nlogn)
        vector<vector<int>> result;
        result.push_back(intervals[0]);


        for(int i = 1; i < intervals.size(); i++){
            if(result.back()[1] < intervals[i][0]){
                //if true, we will push a new interval into result
                result.push_back(intervals[i]);
            }else{
                if(result.back()[1] < intervals[i][1]){
                    //or just extend the last interval in result
                    result.back()[1] = intervals[i][1];
                }
            }
        } 
        return result;
    }
};