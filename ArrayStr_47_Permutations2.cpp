/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10

*/
class Solution {
public:
    vector<vector<int>>result;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return result;
    }

    void backtrack(vector<int>& nums, int idx){
        //base case
        if(idx == nums.size()){
            result.push_back(nums);
            return;
        }
    	unordered_set<int> st;
        for(int i = idx; i < nums.size(); i++){
            if(st.count(nums[i]))continue;
            st.insert(nums[i]);
            swap(nums[i], nums[idx]);
            backtrack(nums, idx+1);
            swap(nums[i], nums[idx]);
        }
    }
};


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        //sorting is used to ensure that identical elements are adjacent to each other
        recursive(nums, 0, nums.size(), res);
        return res;
    }
private://as a good habit
    void recursive(vector<int> nums, int i, int j, vector<vector<int> > &res){
        if(i == j-1){//base case
            res.push_back(nums);
            return;
        }
        for (int k = i; k < j; k++){
            if (i != k && nums[i]==nums[k])continue;//preventing duplicate
            swap(nums[i], nums[k]);
            recursive(nums, i+1, j, res);
        }
    }
};