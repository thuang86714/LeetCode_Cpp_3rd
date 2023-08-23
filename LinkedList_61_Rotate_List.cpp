/*
Given the head of a linked list, rotate the list to the right by k places.

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
*/
#include <cstddef>
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
    ListNode* rotateRight(ListNode* head, int k) {
        //TC O(n), SC O(n)
        //edge case if(!head)return NULL
        if(!head)return NULL;
        //1-indexed <pos,ListNode*>
        int pos = 0;
        unordered_map<int, ListNode*>map;
        while(head){
            pos++;
            map[pos] = head;
            head = head->next;
        }

        k%= pos;
        if(k){
            map[pos]->next = map[1];//from tail link back to head
            map[pos-k]->next = NULL;
            return map[pos-k+1];
        }else{
            return map[1];
        }
    }
};