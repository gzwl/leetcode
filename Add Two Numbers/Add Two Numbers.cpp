/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /*
    这道题直接模拟就可以了，只要注意进位和链表长度这两点就行
 */

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *p1 = l1,*p2 = l2,*fa;
        int in = 0;
        while(p1 && p2) {
            p1->val += p2->val + in;
            in = 0;
            if(p1->val > 9) {
                p1->val %= 10;
                in=1;
            }
            fa = p1;
            p1 = p1->next;p2 = p2->next;
        }
        if(p2) {
            fa->next=p2;p1=p2;
        }
        while(in) {
            if(p1 == NULL) {
                p1= new ListNode(0);
                fa->next = p1;
            }
            p1->val += in;in = 0;
            if(p1->val > 9) {
                p1->val%=10;
                in = 1;
            }
            fa = p1;p1 = p1->next;
        }
        return l1;
    }
};




