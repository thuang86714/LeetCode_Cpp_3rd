/*
Given the head of a linked list, return the list after sorting it in ascending order.

Input: head = [4,2,1,3]
Output: [1,2,3,4]

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
 

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        //using turtle-hare algo to find the mid point of the linked listy
        if(!head || !head->next)return head;
        ListNode *slow = head, *fast = head, *temp;
        while(fast&&fast->next){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        //now temp is the last node in the fisrt half
        //slow is the first nodoe of the second half
        temp->next = nullptr;
        ListNode *L1 = sortList(head);
        ListNode *L2 = sortList(slow);
        return merge(L1, L2);
    }
    ListNode* merge(ListNode* L1, ListNode* L2){
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while(L1 && L2){
            if(L1->val > L2->val){
                cur->next = L2;
                L2 = L2->next;
            }else{
                cur->next = L1;
                L1 = L1->next;
            }
            cur = cur->next;
        }
        // if the first half is longer than second half
        while(L1){
            cur->next = L1;
            L1 = L1->next;
            cur = cur->next;
        }

        while(L2){
            cur->next = L2;
            L2 = L2->next;
            cur = cur->next;
        }
        return dummy->next;
    }
};