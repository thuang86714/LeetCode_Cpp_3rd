#include <vector>
#include <unordered_map>
using namespace std;


class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    //<Old Node, New Node>
    unordered_map<Node*, Node*>map;
    Node* cloneGraph(Node* node) {
        //two edge cases: !node, or node->neighbors.size() ==0
        if(!node)return NULL;
        if(node->neighbors.size() == 0){
            Node *clone = new Node(node->val);
            return clone;
        }

        return recur(node);
    }

    Node* recur(Node* root){
        vector<Node*> Neighbor;
        Node *clone = new Node(root->val);
        map[root] = clone;
        for(auto n:root->neighbors){
            if(map.find(n) != map.end()){
                Neighbor.push_back(map[n]);
            }else{
                Neighbor.push_back(recur(n));
            }
        }
        clone->neighbors = Neighbor;
        return clone;
    }
};