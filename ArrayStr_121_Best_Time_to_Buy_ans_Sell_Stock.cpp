#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = 10001, profit = 0;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < mini){
                mini = prices[i];
            }
            if(prices[i] - mini > profit){
                profit = prices[i] - mini;
            }
        }
        return profit;
    }
};