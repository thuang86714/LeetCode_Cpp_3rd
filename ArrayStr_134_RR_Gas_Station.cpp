#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum_gas = 0, sum_cost = 0, diff = 0, idx = 0;
        for(int i = 0; i < gas.size(); i++){
            sum_gas += gas[i];
            sum_cost += cost[i];

            diff += gas[i]- cost[i];
            if(diff < 0){
                diff = 0;
                idx = i + 1;
            }
        }
        if(sum_gas < sum_cost){
            return -1;
        }else{
            return idx;
        }
    }
};