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
    ListNode* reverseList(ListNode* head) {
        ListNode* root = head;
        while(root && head->next){
            ListNode *p = head->next;
            head->next = p->next;
            p->next = root;
            root = p;
        }
        return root;
    }
};
