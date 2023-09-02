/*
In a Binary Search Tree (BST), an Inorder Successor of a node is defined as the node with the smallest key greater than the key of the input node (see examples below). Given a node inputNode in a BST, you’re asked to write a function findInOrderSuccessor that returns the Inorder Successor of inputNode. If inputNode has no Inorder Successor, return null.

Explain your solution and analyze its time and space complexities.

Example:

In the diagram above, for inputNode whose key = 11

Your function would return:

The Inorder Successor node whose key = 12

Constraints:

[time limit] 5000ms
[input] Node inputNode
[output] Node

*/

#include <iostream>

using namespace std;

struct Node
{
   int key;
   Node *left;
   Node *right;
   Node *parent;
};

// Helper function that allocates a new Node 
Node* newNode( int key )
{
   Node* n = new Node;
   n->key = key;
   n->left = nullptr;
   n->right = nullptr;
   n->parent = nullptr;

   return n;
}

//  Given a binary search tree and a number, inserts a new Node with
//  the given number in the correct place in the tree. Returns the new
//  root pointer which the caller should then use 
Node *insert( Node *root, int key )
{
   // 1) If the tree is empty, return a new single Node
   if( root == nullptr )
      return newNode( key );

   Node *temp;

   // 2) Otherwise, recur down the tree
   if( key < root->key )
   {
      temp = insert( root->left, key );
      root->left = temp;
      temp->parent = root;
   } else
   {
      temp = insert( root->right, key );
      root->right = temp;
      temp->parent = root;
   }

   // Return the (unchanged) Node pointer
   return root;
}

// Return a pointer to a Node in the BST by its key.
// Use this fuction when you need a Node to test your 
// findInOrderSuccessor function on
Node *getNodeByKey( Node *root, int key )
{
   Node *currentNode = root;

   while( currentNode )
   {
      if( key == currentNode->key )
         return currentNode;

      if( key < currentNode->key )
         currentNode = currentNode->left;
      else
         currentNode = currentNode->right;
   }

   return nullptr;
}

Node* findInOrderSuccessor( Node *inputNode )
{
   // your code goes here
  //inorder traversal-->go right
  if(inputNode->right){//9, 12, 20
     inputNode = inputNode->right;
    while(inputNode)inputNode = inputNode->left;
    return inputNode;
  }else{//5, 14, 25
    Node *Parent = inputNode->parent;
    Node *Child = inputNode;
    while(Parent&& Child == Parent->right){
      Child = Parent;
      Parent = Child->parent;
    }
    
    return Parent;

    /*
    Time Complexity: in both cases where either inputNode has a right child or
     doesn’t have one, we are visiting only O(H) number of nodes, 
     where H is the height of the BST. For a balanced BST, since H = log(N), 
     where N is the number of nodes in the BST, the time complexity is O(log(N)). 
     For an unbalanced BST, the time complexity is O(N).

    Space Complexity: throughout the entire algorithm we used only a constant amount
     of space, hence the space complexity is O(1).
    */
  }
}

int main() {
  return 0;
}