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
        //q is FIFO
        queue<Node*> q;
        q.push(root);

        //iterate all nodes in tree with BFS
        while(!q.empty()){
            int size = q.size();
            Node *temp = NULL;

            for(int i = 0; i < size; i++){
                Node *node = q.front();
                q.pop();
                node->next = temp;
                temp = node;

                //push the children of node into q
                //the order matter
                if(node->right)q.push(node->right);
                if(node->left)q.push(node->left);
            }
        }
        return root;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        //credit to Ajna
        // support variables
        Node *currParent = root, *baseChild, *currChild, *nextChild;
        while (currParent) {
            // skipping childless parents - get a family - up to the last node
            while (currParent->next && !currParent->left && !currParent->right) currParent = currParent->next;
            // setting the new basechild, provided we have one at all
            currChild = baseChild = currParent->left ? currParent->left : currParent->right;
            while (currChild) {
                // getting nextChild - either the right sibling of currChild or...
                if (currParent->right && currChild != currParent->right) nextChild = currParent->right;
                // the child of a following parent
                else {
                    // moving to the nextParent, if any
                    currParent = currParent->next;
                    // moving parents, if we have too
                    while (currParent && !currParent->left && !currParent->right) currParent = currParent->next;
                    // setting nextChild to be the next left/right child, if any; NULL otherwise
                    nextChild = currParent ? currParent->left ? currParent->left : currParent->right : currParent;
                }
                currChild->next = nextChild;
                currChild = nextChild;
            }
            // preparing for the next loop
            currParent = baseChild;
        }
        return root;
    }
};