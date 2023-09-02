/*

*/
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
    TreeNode *prev;
    //0 <= Node.val <= 10^5
    int mini = 100001;
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return mini;
    }

    void inorder(TreeNode *node){
        //base case
        if(!node)return;
        inorder(node->left);

        if(prev){
            mini = min(mini, abs(prev->val - node->val));
        }
        prev = node;

        inorder(node->right);
    }
};