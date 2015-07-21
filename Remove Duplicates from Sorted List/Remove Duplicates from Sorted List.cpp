/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //比较基础的题，模拟就可以了
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *p1 = head;
        while(p1 && p1->next){
            ListNode *p2 = p1->next;
            while(p2 && p1->val == p2->val)     p2 = p2->next;
            p1->next = p2;
            p1 = p1->next;
        }
        return head;
    }
};

