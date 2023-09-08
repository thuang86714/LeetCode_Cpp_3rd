class Solution {
public:
    double ans = 1;
    double myPow(double x, int n) {
        //core idea: 2^12 = 4^6
        recur(x, n);
        return ans;
    }

    void recur(double x, int n){
        //base case
        if(n == 0)return;

        if(n%2){
            if(n < 0){
                ans /= x;
            }else{
                ans *= x;
            }
        }

        recur(x*x, n/2);
    }
};