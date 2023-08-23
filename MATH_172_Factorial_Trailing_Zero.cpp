/*
Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

 

Example 1:

Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Example 3:

Input: n = 0
Output: 0
 

Constraints:

0 <= n <= 104
 

Follow up: Could you write a solution that works in logarithmic time complexity?
*/

class Solution {
public:
    int trailingZeroes(int n) {
        //credit to jianchao li
        //TC O(logN), SC O(1)
        /*
        Well, how to count them all? If you try some examples, '
        you may finally get the result, 
        which is n / 5 + n / 25 + n / 125 + .... 
        The idea behind this expression is: all the multiples of 5 will contribute one 5, 
        the multiples of 25 will contribute one more 5 and 
        the multiples of 125 will contribute another one more 5... and so on.
        */

        int count = 0;
        long long int i = 5;
        while(n/i){
            count += n/i;
            i *= 5;
        }
        return count;
    }

};