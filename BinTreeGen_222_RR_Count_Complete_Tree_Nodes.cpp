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
        int lh = 0, rh = 0;
        TreeNode* L = root, *R= root;
        while(L){
            L = L->left;
            lh++;
        }

        while(R){
            R = R->right;
            rh++;
        }

        if(rh == lh){
            return pow(2, lh)-1;
        }else return 1 + countNodes(root->left) + countNodes(root->right);
    }
};