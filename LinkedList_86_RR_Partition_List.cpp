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
        ListNode *smaller = new ListNode(0);//smaller
        ListNode *greater = new ListNode(0);//greater
        ListNode *temp_s = smaller;
        ListNode *temp_g = greater;
        while(head){
            if(head->val < x){
                temp_s->next = head;
                head = head->next;
                temp_s = temp_s->next;
                temp_s->next = NULL;
            }else{
                temp_g->next = head;
                head = head->next;
                temp_g = temp_g->next;
                temp_g->next = NULL;
            }
        }
        temp_s->next = greater->next;

        return smaller->next;
    }
};