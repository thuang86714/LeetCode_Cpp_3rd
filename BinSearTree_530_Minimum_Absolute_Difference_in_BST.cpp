/*
Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

Input: root = [4,2,6,1,3]
Output: 1

Input: root = [1,0,48,null,null,12,49]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 104].
0 <= Node.val <= 105
Note: This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <bits/stdc++.h>
#include <algorithm>
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
    int diff = INT_MAX;
    TreeNode *prev = NULL;
    int getMinimumDifference(TreeNode* root) {
        //intuition bfs(inorder) + vector + sorting
        //not using BST In-order(left-Root-Right) traversal of BST yields sorted sequence.
        //if we could fully leverage the BST, TC O(h), where h is height
        //credit to Ajna
        dfs(root);
        return diff;
    }
    void dfs(TreeNode* node){
        if(node->left)dfs(node->left);

        if(prev) diff = min(diff, abs(prev->val - node->val));
        prev = node;

        if(node->right)dfs(node->right);
    }
};