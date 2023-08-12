/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        //TC O(n), SC O(1)
        //edge case s.size() ==1
        /*
        *if asked at an interview, 
        is to test whether a candidate is able to handle all edge
        cases systematically and write clean codes :-)
        */
        
        int left = 0, right = s.size() - 1;
        while(left < right){
            //isalnum() to see if it's either num or letter
            while(left < right && !isalnum(s[left])){
                left++;
            }
            while(left < right && !isalnum(s[right])){
                right--;
            }
            //tolower to convert all letter into lower case
            if(tolower(s[left++]) != tolower(s[right--]))return false;
        }
        return true;
    }
};