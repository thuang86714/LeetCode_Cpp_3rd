#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        sort(citations.begin(), citations.end());
        int l = 0, r = size-1;
        while(l <= r){
            int mid = (l + r)/2;
            if(citations[mid] < size - mid){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return size - l;
    }
};