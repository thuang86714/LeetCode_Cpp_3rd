/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:

Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.

Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
*/
#include <cstddef>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //c is the len of the cycle
        //L1 is from head to cycle entry point
        //L2 is from entry point to slow-fast meeting point
        //when slow and fast meet, slow has traveled L1+L2
        //fast has traveled L1+ L2+ N*c
        //Plus the distance of fast traveled is twice of slow
        //--> 2*(L1 + L2) = L1 + L2 +N*c
        // L1+L2 = N*c--> L1 = N*c - L2;
        //this tell us that, for slow, when it move forward from the meeting point with fast
        //it travel for N*c - L2, it should meet entry at entry point 
        //key idea: 2()
        ListNode *slow = head, *fast = head, *entry = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                while(entry != slow){
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;//there's no cycle
        
    }
};