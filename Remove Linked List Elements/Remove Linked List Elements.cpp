/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val){        // val at head
            head = head->next;
        }
        ListNode *p = head;
        while(p){                                       //val not at head
            while(p->next && p->next->val == val){
                p->next = p->next->next;
            }
            p = p->next;
        }
        return head;
    }
};
