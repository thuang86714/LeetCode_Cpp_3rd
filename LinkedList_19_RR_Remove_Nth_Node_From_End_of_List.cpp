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
        //need a dummy
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *temp = dummy, *temp2 = dummy; 
        //sort of turtle-hare: len = n + len - n
        for(int i = 0; i < n; i++){
            temp = temp->next;
        }
        while(temp->next){
            temp = temp->next;
            temp2 = temp2->next;
        }
        ListNode *to_be_deleted = temp2->next;
        temp2->next = temp2->next->next;
        delete to_be_deleted;

        return dummy->next;
    }
};