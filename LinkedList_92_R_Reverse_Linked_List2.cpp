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
        ListNode *prev = dummy;
        prev->next = head;
        //left and right are pos in 1-indexed list
        for(int i = 1; i < left; i++){
            prev = prev->next;
        }
        //at this point, prev is the node whose .next is left
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