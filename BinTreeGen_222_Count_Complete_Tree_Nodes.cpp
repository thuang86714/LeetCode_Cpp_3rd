/*
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.
*/
#include <cmath>
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
    int countNodes(TreeNode* root) {
        //TC O(longNlogN), SC O(logN)
        //edge case: root is NULL
        if(!root)return NULL;

        int lh = 0, rh = 0;

        //from the root, we would traverse down to the leaf,
        //to see if the left most tree height == right most tree height
        //if so, then return pow(2, lh)
        TreeNode *l = root, *r = root;
        

        while(l){
            lh++;
            l = l->left;
        }

        while(r){
            rh++;
            r = r->right;
        }

        if(lh == rh)return pow(2, lh)-1;

        return 1 + countNodes(root->left) + countNodes(root->right);

    }
};