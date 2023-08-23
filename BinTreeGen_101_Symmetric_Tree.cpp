/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Input: root = [1,2,2,3,4,4,3]
Output: true

Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 

Follow up: Could you solve it both recursively and iteratively?
*/

#include <queue>
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
    bool isSymmetric(TreeNode* root) {
        //edge case: root is NULL
        if(!root)return true;
        //iteratively
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while(!q.empty()){
            TreeNode *left = q.front();
            q.pop();
            TreeNode *right = q.front();
            q.pop();

            if(!left && !right)continue;
            if(!left || !right)return false;
            if(left->val != right->val)return false;

            //the order to push nodes matter
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }

        return true;
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        //recursively
        //edge case: root is NULL
        if(!root)return true;
        return recur(root->left, root->right);
    }

    bool recur(TreeNode *left, TreeNode *right){
        if(!left && !right)return true;
        if(!left || !right)return false;
        if(left->val != right->val)return false;

        return recur(left->left, right->right) && recur(left->right, right->left);
    }
};