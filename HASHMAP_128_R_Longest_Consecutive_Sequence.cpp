#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //TC O(n), SC O(n)
        //TC not O(n^2) because only when if(map[nums[i]] == true){
        //would the nested while loop take place
        unordered_map<int, bool> map;
        for(int i = 0; i<nums.size(); i++){
            map[nums[i]] = true;
        }
        //set map[nums[i]] to true only if it's the head of the sequence
        for(int i=0; i<nums.size(); i++){
            if(map.count(nums[i]-1) > 0){
                map[nums[i]] = false;
            }
        }
        int maxlen = 0;
        for(int i=0; i<nums.size(); i++){
            if(map[nums[i]] == true){
                int j=0; int count=0;
                while(map.count(nums[i]+j) > 0){
                    j++;
                    count++;
                }
                maxlen = max(count, maxlen);
            }
        }
        return maxlen;
    }
};