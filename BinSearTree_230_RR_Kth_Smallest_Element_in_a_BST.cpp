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
    int ans = 0;
    int kthSmallest(TreeNode* root, int k) {
        recur(root, k);
        return ans;
    }

    void recur(TreeNode* root, int& k){
        //base case
        if(!root)return;
        recur(root->left, k);

        if(--k == 0){
            ans = root->val;
            return;
        }
        recur(root->right, k);
    }
};