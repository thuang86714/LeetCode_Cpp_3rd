#include <cstddef>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    class Node{
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int key, int val){
            this->key = key;
            this->val = val;
            this->prev = NULL;
            this->next = NULL;
        }
    };
    Node *head = new Node(0, 0);
    Node *tail= new Node(0, 0);
    int capacity;
    //<key, Node*>
    unordered_map<int, Node*>map;
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(map.find(key) == map.end())return -1;

        Node *cur = map[key];
        remove(cur);
        insert(cur);
        return cur->val;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){
            remove(map[key]);
        }
        if(map.size() == capacity){
            remove(tail->prev);
        }
        Node *cur = new Node(key, value);
        insert(cur);
    }
private:
    void remove(Node *node){
        int key = node->key;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        map.erase(key);
    }

    void insert(Node *node){
        int key = node->key;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
        map[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */