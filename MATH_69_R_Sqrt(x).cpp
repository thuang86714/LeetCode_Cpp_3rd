class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while(l < r){
            long int mid = (l + r)/2;
            if(mid*mid <= x && (mid+1)*(mid+1) > x)return mid;
            else if(mid*mid > x)r = mid;
            else l = mid + 1;
        }
        return l;

    }
};