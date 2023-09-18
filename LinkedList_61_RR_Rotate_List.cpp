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
        ListNode *tail = head;
        int count = 1;
        while(tail->next){
            count++;
            tail = tail->next;
        }

        tail->next = head;

        k%=count;
        if(count){
            for(int i = 0; i < count - k; i++){
                tail = tail->next;
            }
            ListNode *newHead = tail->next;
            tail->next = NULL;
            return newHead;
        }else{
            return head;
        }
    }
};