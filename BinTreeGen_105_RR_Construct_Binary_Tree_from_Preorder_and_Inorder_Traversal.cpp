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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int PreIdx = 0;
        int n = inorder.size()-1;
        return recur(preorder, inorder, PreIdx, 0, n);
    }

    TreeNode* recur(vector<int>& preorder, vector<int>& inorder, int& PreIdx, int InStart, int InEnd){
        //base case
        if(InStart > InEnd)return NULL;
        
        TreeNode *root = new TreeNode(preorder[PreIdx++]);
        int InIdx = InStart;
        while(inorder[InIdx] != root->val)InIdx++;

        root->left = recur(preorder, inorder, PreIdx, InStart ,InIdx -1);
        root->right = recur(preorder, inorder, PreIdx, InIdx + 1 ,InEnd);

        return root;
    }
};