/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

Follow up: Could you do this in one pass?
*/

#include <unordered_map>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //<pos, Listnode>
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        unordered_map<int, ListNode*>map;
        int count = 0;
        while(head){
            map[count] = head;
            if(head->next){
                head = head->next;
                count++;
            }else{
                break;
            }
        }
        //removing the head;
        if(count < n){
            dummy->next = map[1];
        }else if(n == 1){//removing the tail
            map[count - 1]->next = NULL;
        }else{
            map[count - n]->next = map[count - n +2];
        }

        return dummy->next;
    }
};