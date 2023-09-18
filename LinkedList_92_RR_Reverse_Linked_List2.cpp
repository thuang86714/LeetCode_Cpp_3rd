struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        for(int i = 1; i < left; i++){
            prev = prev->next;
        }
        //at this point, prev is the prev node of left
        ListNode *pivot = prev->next;
        for(int i = left; i < right; i++){
            ListNode *node = pivot->next;
            pivot->next = node->next;
            node->next = prev->next;
            prev->next = node;
        }

        return dummy->next;
    }
};