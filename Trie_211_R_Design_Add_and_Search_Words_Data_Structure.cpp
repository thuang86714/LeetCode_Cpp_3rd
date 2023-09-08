#include <vector>
#include <string>
using namespace std;

class TrieNode{
public:
    bool isEnd = false;
    vector<TrieNode*> next;
    TrieNode(): next(26, nullptr){};
};


class WordDictionary {
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        TrieNode *node = root;
        for(char c:word){
            if(!node->next[c - 'a']){
                node->next[c - 'a'] = new TrieNode();
            }
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        return helper(word, root, 0);
    }
private:
    TrieNode *root = new TrieNode();
    bool helper(string s, TrieNode *node, int idx){
        if(idx == s.size()){
            return node->isEnd;
        }

        if(s[idx] != '.'){
            node = node->next[s[idx] - 'a'];
            return node && helper(s, node, idx+1);
        }

        if(s[idx] == '.'){
            for(int i = 0; i < 26; i++){
                if(node->next[i] && helper(s, node->next[i], idx+1))return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */