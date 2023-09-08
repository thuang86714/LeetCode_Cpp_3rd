class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0;
        int five = 5;
        while(n/five >= 1){
            sum += n/five;
            five *= 5;
        }
        return sum;
    }
};