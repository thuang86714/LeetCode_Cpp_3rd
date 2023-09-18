#include <unordered_map>
#include <stack>
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
    int pairSum(ListNode* head) {
        stack<ListNode*> st;
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        //pushing the nodes in second half into stack
        while(slow){
            st.push(slow);
            slow = slow->next;
        }
        int maxi = 0;
        while(!st.empty()){
            int sum = head->val + st.top()->val;
            head = head->next;
            st.pop();
            maxi = max(sum, maxi);
        }
        return maxi;

    }
};


class Solution {
public:
    int pairSum(ListNode* head) {
        int count = 0;
        ListNode *dummy = head;
        unordered_map<int, ListNode*> map;
        while(dummy){
            map[count] = dummy;
            count++;
            dummy = dummy->next;
        }
        int maxi = 0;
        for(int i = 0; i <= count/2-1; i++){
            int sum = map[i]->val + map[count - 1 - i]->val;
            maxi = max(maxi, sum);
        }
        return maxi;
        
    }
};