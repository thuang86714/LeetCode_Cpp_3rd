#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //edge case: amount == 0
        if(!amount)return 0;
        //sorting to make sure it's ordered
        sort(coins.begin(), coins.end());
        //edge case amount < coins.front()
        if(amount < coins.front())return -1;

        vector<int> dp(amount + 1, amount + 1);
        //base case
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int coin:coins){
                if(i - coin >= 0){
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        if(dp.back() > amount){
            return -1;
        }else{
            return dp.back();
        }
    }
};