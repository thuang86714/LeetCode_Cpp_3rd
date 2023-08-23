/*
Given the root of a binary tree, invert the tree, and return its root.

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Input: root = [2,1,3]
Output: [2,3,1]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
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
    TreeNode* invertTree(TreeNode* root) {
        //edge case: root is NULL
        //TC O(n), SC O(n)
        if(!root)return NULL;
        //BFS
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            TreeNode *temp = node->left;
            node->left = node->right;
            node->right = temp;

            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }

        return root;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        //edge case root == NULL
        //TC O(n), SC O(logn)
        if(!root)return NULL;
        //DFS
        TreeNode *newR = root->left;
        TreeNode *newL = root->right;
        root->left = invertTree(newL);
        root->right = invertTree(newR);

        return root;
    }
};