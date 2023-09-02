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
        //TC O(logn^2), SC O(logn)
        /*
        Explanation credit goes to StefanPochmann
        Since I halve the tree in every recursive step, 
        I have O(log(n)) steps. Finding a height costs O(log(n)). So overall O(log(n)^2).
        */
        if(!root)return NULL;
        int lh = 0, rh = 0;
        TreeNode *l = root, *r = root;

        //Finding the left height costs O(log(n))
        while(l){
            lh++;
            l = l->left;
        }

        //Finding the right height costs O(log(n))
        while(r){
            rh++;
            r = r->right;
        }

        if(lh == rh)return pow(2, lh)-1;
        //I halve the tree in every recursive step
        else return 1 + countNodes(root->left) + countNodes(root->right);
    }
};