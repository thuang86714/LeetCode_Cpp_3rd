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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return NULL;
        int len = 1;
        ListNode *tail = head;

        while(tail->next){
            len++;
            tail = tail->next;
        }

        //tail at this point is the tail of the linked list
        //circle up
        tail->next = head;

        k %= len;
        if(k){
            for(int i = 0; i < len - k; i++)tail = tail->next;
        }
        ListNode *newHead = tail->next;
        tail->next = NULL;
        return newHead;
    }
};