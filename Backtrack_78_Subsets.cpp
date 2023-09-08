#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        backtrack(nums, temp, 0);
        return result;
    }

    void backtrack(vector<int>& nums, vector<int>& temp, int idx){
        result.push_back(temp);
        if(idx > nums.size())return;

        for(int i = idx; i < nums.size(); i++){
            temp.push_back(nums[i]);
            backtrack(nums, temp, i+1);
            temp.pop_back();
        }
    }
};