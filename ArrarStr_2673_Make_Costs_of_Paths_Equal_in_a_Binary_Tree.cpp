#include <vector>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        //1-indexed
        //leaves that share same parent should have equal val
        //n = pow(2, x) - 1, where x is the height of the tree
        //left(n) = 2*n +1, right(n) = 2*n +2
        //credit to lee215
        //traverse all nodes in second last level-->bottom up
        //TC O(n), SC O(1)
        int ans = 0;
        for(int i = n/2-1; i >= 0; i--){
            int l = 2*i+1, r = 2*i+2;
            ans += abs(cost[l] - cost[r]);
            cost[i] += max(cost[l], cost[r]);
        }
        return ans;
    }
};