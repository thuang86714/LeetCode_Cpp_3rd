#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        //<sum, <nums1[i], nums2[j]>>
        priority_queue<pair<int, pair<int, int>>>pq;

        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                int sum = nums1[i] + nums2[j];
                if(pq.size() < k){
                    pq.push({sum, {nums1[i], nums2[j]}});
                }else if(pq.top().first > sum){
                    pq.pop();
                    pq.push({sum, {nums1[i], nums2[j]}});
                }else{
                    break;
                }
            }
        }

        vector<vector<int>> result;
        while(!pq.empty()){
            vector<int> temp;
            temp.push_back(pq.top().second.first);
            temp.push_back(pq.top().second.second);
            result.push_back(temp);
            pq.pop();
        }
        return result;
    }
};