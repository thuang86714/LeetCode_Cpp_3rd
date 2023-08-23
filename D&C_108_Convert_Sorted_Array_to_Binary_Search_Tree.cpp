/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a 
height-balanced
binary search tree.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recur(nums, 0, nums.size());
    }

    TreeNode* recur(vector<int>& nums, int start, int end){
        //base case
        if(start >= end)return NULL;
        int mid = (start + end)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = recur(nums, start, mid);
        root->right = recur(nums, mid+1, end);
        return root;
    }
};