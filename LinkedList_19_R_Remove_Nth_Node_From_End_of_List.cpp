#include <unordered_map>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        ListNode *right = dummy, *left =dummy;
        dummy->next = head;
        for(int i = 0; i < n; i++){
            right = right->next;
        }

        while(right->next){
            right = right->next;
            left = left->next;
        }
        ListNode *to_be_deleted = left->next;
        left->next = left->next->next;
        delete to_be_deleted;
        return dummy->next;

    }
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //<count, ListNode*>
        unordered_map<int, ListNode*> temp;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        int count = 0;
        while(head){
            temp[count] = head;
            if(head->next){
                head = head->next;
                count++;
            }else{
                break;
            }
        }
        
        if(n > count){
            dummy->next = temp[1];
        }else if(n == 1){
            temp[count-1]->next = NULL;
        }else{
            temp[count - n]->next = temp[count - n +2];
        }
        
        return dummy->next;
    }
};