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
        ListNode *small_head = new ListNode(0), *great_head = new ListNode(0);
        ListNode *small_temp = small_head, *great_temp = great_head;
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
        small_temp->next = great_head->next;
        return small_head->next;
    }
};