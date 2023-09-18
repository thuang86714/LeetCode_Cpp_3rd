#include <vector>
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size() - 1;
        int PostIdx = n;
        return recur(inorder, postorder, 0, n, PostIdx);
    }

    TreeNode* recur(vector<int>& inorder, vector<int>& postorder, int InStart, int InEnd, int& PostIdx){
        //base case
        if(InStart > InEnd)return NULL;

        TreeNode *root = new TreeNode(postorder[PostIdx--]);
        int InIdx = InStart;
        while(inorder[InIdx] != root->val)InIdx++;

        root->right = recur(inorder, postorder, InIdx + 1, InEnd, PostIdx);
        root->left = recur(inorder, postorder, InStart, InIdx-1, PostIdx);
        
        return root;
    }
};