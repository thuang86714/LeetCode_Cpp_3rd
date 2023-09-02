/*
A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.

For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.

 

Example 1:

Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
Output: 1
Example 2:

Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
Output: 2
 

Constraints:

0 <= bank.length <= 10
startGene.length == endGene.length == bank[i].length == 8
startGene, endGene, and bank[i] consist of only the characters ['A', 'C', 'G', 'T'].
*/

#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        //one mutation is a level
        //do bfs to see if there's a match at each level
        unordered_set<string> dict{bank.begin(), bank.end()};

        //edge case: ednGene not in bank
        if(!dict.count(endGene))return -1;

        int step = 0;

        queue<string>q;
        q.push(startGene);

        while(!q.empty()){
            //size = number of nodes at each level
            int size = q.size();
            for(int i = 0; i < size; i++){
                string s = q.front();
                q.pop();

                if(s == endGene)return step;
                //avoid redandunt traversing
                dict.erase(s);
                for(int j = 0; j < 8; j++){
                    string temp = s;
                    temp[j] = 'A';
                    if(dict.find(temp) != dict.end())q.push(temp);
                    temp[j] = 'T';
                    if(dict.find(temp) != dict.end())q.push(temp);
                    temp[j] = 'C';
                    if(dict.find(temp) != dict.end())q.push(temp);
                    temp[j] = 'G';
                    if(dict.find(temp) != dict.end())q.push(temp);
                }
            }
            step++;
        }
        return -1;
    }
};