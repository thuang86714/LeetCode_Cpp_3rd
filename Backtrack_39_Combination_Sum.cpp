/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
 

Constraints:

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //would be much more efficient after sorting
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> temp;
        recur(candidates, result, temp, target, 0);
        return result;
    }

    void recur(vector<int>& candidates, vector<vector<int>>& result, vector<int>& temp,int target, int i){
        if(target == 0){
            result.push_back(temp);
            return;
        }

        while(i < candidates.size() && target >= candidates[i]){
            temp.push_back(candidates[i]);
            //we dont i+1 here, since the same candidates[i] could be chosen for unlimited times
            recur(candidates, result, temp, target - candidates[i], i);
            i++;
            temp.pop_back();
        }
    }
};