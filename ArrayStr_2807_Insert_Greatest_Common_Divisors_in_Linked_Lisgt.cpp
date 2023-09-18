#include <numeric>
#include <algorithm>
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        //edge case: heas has no next
        if(!head->next)return head;
        //credit to kreakEmp
        //TC O(n), SC O(1)
        ListNode *ptr = head;
        while(ptr->next){
            ListNode *temp = new ListNode(gcd(ptr->val, ptr->next->val) ,ptr->next);
            ptr->next = temp;
            ptr = temp->next;
        }
        return head;
    }
};