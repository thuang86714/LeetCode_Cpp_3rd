class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp = {};
        backtrack(n, k, temp, 1);
        return result;
    }

    void backtrack(int n , int k, vector<int>& temp, int idx){
        //base case
        if(temp.size() == k){
            result.push_back(temp);
            return;
        }

        for(int i = idx; i <= n; i++){
            temp.push_back(i);
            backtrack(n, k, temp, i+1);
            temp.pop_back();
        }
    }
};