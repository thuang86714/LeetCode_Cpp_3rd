#include <queue>
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
    vector<int> rightSideView(TreeNode* root) {
        //edge case root is NULL;
        if(!root)return {};
        //queue + BFS
        vector<int> result;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode *node = q.front();
                q.pop();
                if(i == 0){
                    result.push_back(node->val);
                }

                if(node->right)q.push(node->right);
                if(node->left)q.push(node->left);
            }
        }
        return result;
    }
};