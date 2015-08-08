/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /*
    首先通过快慢指针的方法找到链表的中点
    然后把中点后面的部分就地逆置
    最后把链表的前半部分和后半部分合并就可以了
     O(n) time and O(1) space
*/
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *quick = head,*low = head;
        //快慢指针
        while(quick && low){
            if(quick->next)     quick = quick->next->next;
            else    quick = NULL;
            low = low->next;
        }
        //找到中点逆置后半部分
        ListNode *p1 = reverselist(low);
        ListNode *p2 = head;
        while(p1){
            ListNode *p3 = p2->next;
            ListNode *p4 = p1->next;
            p2->next = p1;
            p1->next = p3;
            p1 = p4;
            p2 = p3;
        }
        if(p2)  p2->next = 0;
    }
    ListNode* reverselist(ListNode *p)
    {
        ListNode* head = p;
        while(p && p->next){
            ListNode* q = p->next;
            p->next = q->next;
            q->next = head;
            head = q;
        }
        return head;
    }
};
