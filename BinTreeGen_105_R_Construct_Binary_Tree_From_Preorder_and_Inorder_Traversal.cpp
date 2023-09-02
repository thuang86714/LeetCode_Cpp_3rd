/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size(), PreIdx = 0;
        return recur(preorder, inorder, 0, n - 1, PreIdx);
    }

    TreeNode* recur(vector<int>& preorder, vector<int>& inorder, int InStart, int InEnd, int& PreIdx){
        //base case
        if(InStart > InEnd)return NULL;

        TreeNode *root = new TreeNode(preorder[PreIdx++]);
        int InIdx = InStart;
        while(inorder[InIdx] != root->val)InIdx++;

        root->left = recur(preorder, inorder, InStart, InIdx-1, PreIdx);
        root->right = recur(preorder, inorder, InIdx+1, InEnd, PreIdx);

        return root;
    }
};