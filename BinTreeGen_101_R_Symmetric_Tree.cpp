/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:
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
        //TC O(n), SC O(logn)
        //base case
        if(!root)return false;
        return dfs(root->right, root->left);
    }

    bool dfs(TreeNode* r, TreeNode *l){
        //base case
        if(!r && !l)return true;
        if(!r || !l)return false;

        if(r->val != l->val)return false;
        
        return dfs(r->right, l->left) &&dfs(r->left, l->right);
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)return false;
        //queue+BFS
        queue<TreeNode*> q;
        //the order of pushing nodes matters
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

            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};