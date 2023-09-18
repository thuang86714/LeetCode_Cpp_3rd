#include <cstddef>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }

    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        //base case
        if(!root)return NULL;
        if(root == p)return p;
        if(root == q)return q;

        TreeNode *l = dfs(root->left, p, q);
        TreeNode *r = dfs(root->right, p, q);

        if(!l && r){
           return r; 
        }else if(l && !r){
            return l;
        }else if(!l && !r){
            return NULL;
        }else{
            return root;
        }

    }
};