/*
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m 
substrings
 respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true
 

Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.
 

Follow up: Could you solve it using only O(s2.length) additional memory space?
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        //credit to TLDRAlgos
        //TC O(m*n), SC O(n)
        
        
        //edge case: if s3.len != s1.len+ s2.len
        if(s3.size() != s1.size() + s2.size())return false;
        if(s1.size() < s2.size())swap(s1, s2);
        int m = s1.size(), n = s2.size();

        /*
        this paragraph's credit to sherryxmhe
        So if both s1 and s2 is currently empty, s3 is empty too, 
        and it is considered interleaving. If only s1 is empty, 
        then if previous s2 position is interleaving and current s2 position char 
        is equal to s3 current position char, it is considered interleaving. 
        similar idea applies to when s2 is empty. when both s1 and s2 is not empty, 
        then if we arrive i, j from i-1, j, then if i-1,j is already interleaving 
        and i and current s3 position equal, it s interleaving. 
        If we arrive i,j from i, j-1, then if i, j-1 is already interleaving and j and current s3 position equal.
        It is interleaving.
        */

        vector<bool> cur(n + 1, false);
        cur[0] = true;
        for(int j = 1; j <= n; j++){//base case1
            cur[j] = (s3[j - 1] == s2[j - 1] && cur[j - 1]);
        }

        for(int i = 1; i <= m; i++){
            cur[0] = (s3[i - 1] == s1[i - 1] && cur[0]);//base case2
            for(int j = 1; j <= n; j++){
                cur[j] = (s3[i + j -1] == s1[i - 1] && cur[j]) || (s3[i + j - 1] == s2[j - 1] && cur[j - 1]);
            }
        }

        return cur.back();
    }
};