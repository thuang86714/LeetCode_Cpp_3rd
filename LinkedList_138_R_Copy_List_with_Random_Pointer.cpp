#include <unordered_map>
#include <cstddef>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    //<Old Node, New Node>
    unordered_map<Node*, Node*>map;
    Node* copyRandomList(Node* head) {
        //base case
        if(!head)return NULL;

        Node *clone = head;
        while(clone){
            map[clone] = new Node(clone->val);
            clone = clone->next;
        }

        clone = head;
        while(clone){
            map[clone]->next = map[clone->next];
            map[clone]->random = map[clone->random];
            clone = clone->next; 
        }
        return map[head];
    }

    
};