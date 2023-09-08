#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int water = 0;
        while(l < r){
            int h = min(height[l], height[r]);
            int w = r - l;
            water = max(water, h*w);
            while(l < r && h >= height[l])l++;
            while(l < r && h >= height[r])r--;
        }
        return water;
    }
};