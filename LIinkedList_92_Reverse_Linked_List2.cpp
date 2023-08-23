/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 

Follow up: Could you do it in one pass?
*/

#include <unordered_map>
#include <cstddef>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //credit to StefanPochmann
        //TC O(right - 1) SC O(1)
        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy;
        dummy->next = head;
        for(int i = 1; i < left; i++){//would eventually reach prev node of left
            prev = prev->next;
        }
        //pivot->val == left
        ListNode *pivot = prev->next;
        for(int i = left; i < right; i++){
            ListNode *node = pivot->next;
            pivot->next = node->next;
            node->next = prev->next;
            prev->next = node;
        }
        return dummy->next;
    }
};