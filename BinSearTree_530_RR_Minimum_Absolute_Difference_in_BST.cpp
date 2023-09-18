#include <algorithm>
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
    TreeNode* prev;
    int diff = 100001;
    int getMinimumDifference(TreeNode* root) {
        recur(root);
        return diff;
    }

    void recur(TreeNode* root){
        if(!root)return;
        if(root->left)recur(root->left);

        if(prev){
            diff = min(diff, abs(prev->val - root->val));
        }
        prev = root;

        recur(root->right);
    }
};