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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return false;
        if(root->val == targetSum && !root->left && !root->right)return true;
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};
  //to improve
  //too nervous->just do more mock interview
  //too silent-->keep talking
  //no side notes
  //lastly, not able to come up with a solution
  
  //I like
  //able to get the hints
  //willing to write down things to help me understand