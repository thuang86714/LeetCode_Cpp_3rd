/*
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]
 

Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200
*/

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
    ListNode* partition(ListNode* head, int x) {
        //divide and conquer
        //TC O(size of linked list), SC O(1)
        //divide the linked list into smaller part and greater part
        ListNode *small_dummy = new ListNode(0);
        ListNode *great_dummy = new ListNode(0);
        ListNode *small_temp = small_dummy, *great_temp = great_dummy;
        while(head){
            if(head->val < x){
                small_temp->next = head;
                small_temp = small_temp->next;
                head = head->next;
                small_temp->next = NULL;
            }else{
                great_temp->next = head;
                great_temp = great_temp->next;
                head = head->next;
                great_temp->next = NULL;
            }
            
        }
        //link up the smaller part and the great part
        small_temp->next = great_dummy->next;

        return small_dummy->next;
    }
};