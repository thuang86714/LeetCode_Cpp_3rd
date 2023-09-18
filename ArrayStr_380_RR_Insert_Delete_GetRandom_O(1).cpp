#include <unordered_map>
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;


class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(map.find(val) == map.end()){
            dict.push_back(val);
            map[val] = dict.size()-1;
            return true;
        }else{
            return false;
        }
    }
    
    bool remove(int val) {
        if(map.find(val) != map.end()){
            int pos = map[val];
            map[dict.back()] = pos;
            swap(dict[pos], dict.back());
            dict.pop_back();
            map.erase(val);
            return true;
        }else{
            return false;
        }
    }
    
    int getRandom() {
        return dict[rand()%dict.size()];
    }
private:
    unordered_map<int ,int>map;
    vector<int> dict;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */