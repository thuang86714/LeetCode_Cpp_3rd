/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]
 

Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //TC O(n^2), SC O(n)
        //credit to archit91
        int PostIdx = postorder.size()-1;
        int n = inorder.size();
        return recur(inorder, postorder, 0, n-1, PostIdx);
    }

    TreeNode* recur(vector<int>& inorder, vector<int>& postorder, int InStart, int InEnd, int& PostIdx){
        //base case
        if(InStart > InEnd)return NULL;
        //base case2
        if(PostIdx <0)return NULL;
        TreeNode *root = new TreeNode(postorder[PostIdx--]);

        int InIdx = InStart;
        while(inorder[InIdx] != root->val)InIdx++;

        //order matters, since postorder: left->right->root
        root->right = recur(inorder, postorder, InIdx+1, InEnd, PostIdx);
        root->left = recur(inorder, postorder, InStart, InIdx-1, PostIdx);
        

        return root;
    }
};