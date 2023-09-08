#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //using set to remove duplicate
        //then put all elements in priority queue
        //pop till k
        
        //then put all elements in priority queue
        priority_queue<int> pq = {nums.begin(), nums.end()};
        int res;
        while(k > 0&&!pq.empty()){
            res = pq.top();
            pq.pop();
            k--;
        }
        return res;
    }
};