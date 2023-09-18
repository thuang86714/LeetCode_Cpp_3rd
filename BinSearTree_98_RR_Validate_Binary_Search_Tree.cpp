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
    TreeNode *prev;
    bool isValidBST(TreeNode* root) {
        return recur(root);
    }

    bool recur(TreeNode *root){
        //base case
        if(!root)return true;

        if(!recur(root->left))return false;

        if(prev){
            if(prev->val >= root->val)return false; 
        }
        prev = root;
        return recur(root->right);
        
    }
};