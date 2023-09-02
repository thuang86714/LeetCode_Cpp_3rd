/*
Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Example 1:
Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
Example 2:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 6000].
-100 <= Node.val <= 100
 

Follow-up:

You may only use constant extra space.
The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.
*/



#include <cstddef>
#include <queue>
using namespace std;


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        //TC O(n), SC O(n)
        //edge case root is NULL
        if(!root)return NULL;
        //BFS + queue-> int size = the No. of node at that level
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            Node *temp = NULL;
            for(int i = 0; i < size; i++){
                Node *node = q.front();
                q.pop();
                
                node->next = temp;
                temp = node;
                
                //the order of pushing left and right nodes matters
                if(node->right)q.push(node->right);
                if(node->left)q.push(node->left);
            }
        }
        return root;
    }
};

//space optimized ver
class Solution {
public:
    Node* connect(Node* root) {
        //TC O(n), SC O(1)
        Node* curParent = root, *baseChild, *curChild, *nextChild;
        while(curParent){
            // skipping childless parents - get a family - up to the last node
            while(curParent->next && !curParent->left && !curParent->right)curParent = curParent->next;

            // setting the new basechild, provided we have one at all
            if(curParent->left){
                curChild = curParent->left;
                baseChild = curParent->left;
            }else{
                curChild = curParent->right;
                baseChild = curParent->right;
            }

            while(curChild){
                if(curParent->right && curChild != curParent->right)nextChild = curParent->right;
                else{
                    curParent = curParent->next;
                    while(curParent && !curParent->left && !curParent->right)curParent = curParent->next;
                    if(curParent){
                        if(curParent->left){
                            nextChild = curParent->left;
                        }else{
                            nextChild = curParent->right;
                        }
                    }else{
                        nextChild = curParent;
                    }
                }
                curChild->next = nextChild;
                curChild = nextChild;
            }
            curParent = baseChild;
        }
        return root;
    }
};