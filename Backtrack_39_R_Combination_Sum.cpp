class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        backtrack(candidates, target, temp, 0);
        return result;
    }

    void backtrack(vector<int>& candidates, int target, vector<int>& temp, int idx){
        if(target < 0)return;
        if(target == 0){
            result.push_back(temp);
            return;
        }

        for(int i = idx; i < candidates.size(); i++){
            temp.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], temp, i);
            temp.pop_back();
        }
    }

};