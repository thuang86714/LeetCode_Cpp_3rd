#include <unordered_set>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> dict {bank.begin(), bank.end()};

        int count = 0;
        queue<string>q;
        q.push(startGene);

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                string s = q.front();
                q.pop();

                if(s == endGene)return count;
                dict.erase(s);
                for(int i = 0; i < s.size(); i++){
                    char temp = s[i];
                    s[i] = 'A';
                    if(dict.find(s) != dict.end())q.push(s);
                    s[i] = 'C';
                    if(dict.find(s) != dict.end())q.push(s);
                    s[i] = 'G';
                    if(dict.find(s) != dict.end())q.push(s);
                    s[i] = 'T';
                    if(dict.find(s) != dict.end())q.push(s);
                    s[i] = temp;
                }
            }
            count++;
        }
        return -1;
    }
};