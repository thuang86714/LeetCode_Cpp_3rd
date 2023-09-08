#include <unordered_map>
#include <cstddef>
using namespace std;


class LRUCache {
public:
    class node{
    public:
        node *prev;
        node *next;
        int key;
        int val;
        node(int key, int val){
            this->key = key;
            this->val = val;
            this->prev = NULL;
            this->next = NULL;
        }
    };
    //<key, node*>
    unordered_map<int, node*> map;
    int capacity;
    node *head = new node(0, 0);
    node *tail = new node(0, 0);

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(map.find(key) == map.end())return -1;

        node *current = map[key];
        remove(current);
        insert(current);
        return current->val;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end())remove(map[key]);

        if(map.size() == capacity){
            remove(tail->prev);
        }
        insert(new node(key, value));
    }
private:
    void insert(node *node){
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
        map[node->key] = node;
    }

    void remove(node *node){
        map.erase(node->key);
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */