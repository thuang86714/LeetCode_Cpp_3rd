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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)return head;
        //merge sort
        //turtle-hare algo to find the mid point of linked list
        
        ListNode *slow = head, *fast = head, *temp = head;
        while(fast && fast->next){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        //temp is the tail of the first half, slow is the head of second half
        temp->next = NULL;
        ListNode *L1 = sortList(head);
        ListNode *L2 = sortList(slow);
        return merge(L1, L2);
    }

    ListNode* merge(ListNode *L1, ListNode *L2){
        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;
        while(L1 && L2){
            if(L1->val > L2->val){
                dummy->next = L2;
                L2 = L2->next;
            }else{
                dummy->next = L1;
                L1 = L1->next;
            }
            dummy = dummy->next;
        }

        //in case first half of linked list is longer
        while(L1){
            dummy->next = L1;
            L1 = L1->next;
            dummy = dummy->next;
        }
        //in case second half of linked list is longer
        while(L2){
            dummy->next = L2;
            L2 = L2->next;
            dummy = dummy->next;
        }
        return head->next;
    }
};