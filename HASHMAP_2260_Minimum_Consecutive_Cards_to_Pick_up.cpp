/*
You are given an integer array cards where cards[i] represents the value of the ith card. A pair of cards are matching if the cards have the same value.

Return the minimum number of consecutive cards you have to pick up to have a pair of matching cards among the picked cards. If it is impossible to have matching cards, return -1.

 

Example 1:

Input: cards = [3,4,2,3,4,7]
Output: 4
Explanation: We can pick up the cards [3,4,2,3] which contain a matching pair of cards with value 3. Note that picking up the cards [4,2,3,4] is also optimal.
Example 2:

Input: cards = [1,0,5,3]
Output: -1
Explanation: There is no way to pick up a set of consecutive cards that contain a pair of matching cards.
 

Constraints:

1 <= cards.length <= 105
0 <= cards[i] <= 106

*/

#include <unordered_map>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        //TC O(n), SC O(n)
        //<val, pos>
        //cards = [3,4,2,3,4,7]
        unordered_map<int, int>map;
        //1 <= cards.length <= 10^5
        int mini = 100001;
        for(int i = 0; i < cards.size(); i++){
            //we've found head tail
            // i = 3, map[3] = 0--> 3 - 0 + 1 = 4
            if(map.find(cards[i]) != map.end()){
                mini = min(mini, i - map[cards[i]] + 1);
                map[cards[i]] = i;
            }else{
                map[cards[i]] = i;
                //map= {(3, 0), (4, 1), (2, 2), }
            }
        }
        //If it is impossible to have matching cards, return -1.
        if(mini == 100001){
            return -1;
        }else{
            return mini;
        }
        
    }
};