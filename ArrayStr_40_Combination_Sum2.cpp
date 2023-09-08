/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30

*/
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //TC (2^n), SC O(n)
        //int in arr not unique, but all are natureal nums
        //len of each sol is not fixed
        //(1, 2, 2, 2, 5), t = 5
        //(1, 2, 2), (5)
        //to make duplicates adjacent
        sort(candidates.begin(), candidates.end());
          
        int n = candidates.size();
        int i = 0;
        vector<int> temp;
        backtrack(candidates, target, temp, 0);
        return result;
    }
    void backtrack(vector<int>& candidates, int target, vector<int> temp, int idx){
        //base case
        if(target < 0)return;
        //base case2
        if(target == 0){
            result.push_back(temp);
            return;
        }

        for(int i = idx; i < candidates.size(); i++){
            //skip duplicates
            if(i > idx && candidates[i] == candidates[i-1])continue;
            temp.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], temp, i+1);
            temp.pop_back();
        }
    }
};