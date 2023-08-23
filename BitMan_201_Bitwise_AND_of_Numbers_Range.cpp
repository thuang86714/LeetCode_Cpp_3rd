/*
Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

 

Example 1:

Input: left = 5, right = 7
Output: 4
Example 2:

Input: left = 0, right = 0
Output: 0
Example 3:

Input: left = 1, right = 2147483647
Output: 0
 

Constraints:

0 <= left <= right <= 231 - 1

*/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        //credit to Ajna
        int count = 0;
        /*
        Once we are done shaving bits off, once we reach a situation so that l == r, 
        we can just return that number, shifted left by the amount of steps we did before, 
        to remove the diverging bits.

        For extra optimisation, 
        we can actually stop as soon as we shaved off the last bit of l (ie: l == 0),
        since there would be no point on going on 
        in that case and shave more bits out of r: 
        we just know that there are no matching bits in that range.
        */
        while(left && left != right)left >>= 1, right>>=1, count++;
        return left << count;
    }
};