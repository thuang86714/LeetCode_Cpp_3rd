/*
You are given a 0-indexed integer array nums of length n.

The numbers from 0 to n - 1 are divided into three groups numbered from 1 to 3, where number i belongs to group nums[i]. Notice that some groups may be empty.

You are allowed to perform this operation any number of times:

Pick number x and change its group. More formally, change nums[x] to any number from 1 to 3.
A new array res is constructed using the following procedure:

Sort the numbers in each group independently.
Append the elements of groups 1, 2, and 3 to res in this order.
Array nums is called a beautiful array if the constructed array res is sorted in non-decreasing order.

Return the minimum number of operations to make nums a beautiful array.

 

Example 1:

Input: nums = [2,1,3,2,1]
Output: 3
Explanation: It's optimal to perform three operations:
1. change nums[0] to 1.
2. change nums[2] to 1.
3. change nums[3] to 1.
After performing the operations and sorting the numbers in each group, group 1 becomes equal to [0,1,2,3,4] and group 2 and group 3 become empty. Hence, res is equal to [0,1,2,3,4] which is sorted in non-decreasing order.
It can be proven that there is no valid sequence of less than three operations.
Example 2:

Input: nums = [1,3,2,1,3,3]
Output: 2
Explanation: It's optimal to perform two operations:
1. change nums[1] to 1.
2. change nums[2] to 1.
After performing the operations and sorting the numbers in each group, group 1 becomes equal to [0,1,2,3], group 2 becomes empty, and group 3 becomes equal to [4,5]. Hence, res is equal to [0,1,2,3,4,5] which is sorted in non-decreasing order.
It can be proven that there is no valid sequence of less than two operations.
Example 3:

Input: nums = [2,2,2,2,3,3]
Output: 0
Explanation: It's optimal to not perform operations.
After sorting the numbers in each group, group 1 becomes empty, group 2 becomes equal to [0,1,2,3] and group 3 becomes equal to [4,5]. Hence, res is equal to [0,1,2,3,4,5] which is sorted in non-decreasing order.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 3
*/
//credit to lee215
//The question asks us to make A[i] increasing from 1 to 3.

#include <bits/stdc++.h>
using namespace std;

//brute force-->TC O(n^2), SC O(1)
class Solution{
    int minimumOperations(vector<int>& A) {
    int n = A.size(), res = n;
    for (int i = 0; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int cur = 0;
            for (int k = 0; k < n; k++) {
                if (k < i) {
                    cur += A[k] != 1;
                } else if (k < j) {
                    cur += A[k] != 2;
                } else {
                    cur += A[k] != 3;
                }
            }
            res = min(res, cur);
        }
    }
    return res;
}
};

/*
DP
Use a presents the operation to make sequence all 1s
Use b presents the operation to make sequence incresing from 1 to 2
Use c presents the operation to make sequence incresing from 1 to 3

Time O(kn), Space O(k), where k = 3.

*/

class Solution{
    int minimumOperations(vector<int>& A) {
    int a = 0, b = 0, c = 0;
    for (int x: A) {
        a += x != 1;
        b = min(a, b + (x != 2));
        c = min(b, c + (x != 3));
    }
    return c;
}

};

//DP-->TC O(kn), SC O(k)
/*
Initial all dp[k] as n, since at most n elements.
Iterate each a in A,
and we update dp[a]--,
since one more a in the array,
we save one operation.

Then update dp[k] = min(dp[k], dp[k - 1]),
because sequence from 1 to k - 1 is a special kind of
sequence from 1 to k,
but missing k in the sequence.

*/
class Solution{
    int minimumOperations(vector<int>& A) {
    vector<int> dp(4, A.size());
    for (int a : A) {
        dp[a]--;
        dp[2] = min(dp[2], dp[1]);
        dp[3] = min(dp[3], dp[2]);
    }
    return dp[3];
    }
};