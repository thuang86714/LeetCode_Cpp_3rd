/*
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 

Constraints:

1 <= word.length <= 25
word in addWord consists of lowercase English letters.
word in search consist of '.' or lowercase English letters.
There will be at most 2 dots in word for search queries.
At most 104 calls will be made to addWord and search.
*/
#include <bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    bool isEnd = false;
    vector<TrieNode*> next;
    TrieNode(): next(26,nullptr){};
    
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
    bool helper(string word, TrieNode *node, int pos){
        if(pos == word.size())return node->isEnd;

        if(word[pos] != '.'){
            node = node->next[word[pos] - 'a'];
            //node->next[word[pos] - 'a'] could be null, hence the new node could be null
            return node && helper(word, node, pos+1);
        }

        if(word[pos] == '.'){
            for(int i = 0; i < 26; i++){
                if(node->next[i] && helper(word, node->next[i], pos+1))return true;
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