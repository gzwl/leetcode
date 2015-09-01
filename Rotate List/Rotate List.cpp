/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /*
    1.首先求下链表的长度len,然后k%=len
    2.链表尾部和头部连接
    2.找到链表的len-k处断开即可
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* p = head;
        ListNode* last;
        int len = 0;

        //求出长度
        while(p) {
            last = p;
            p = p->next;
            ++len;
        }
        if(len == 0 || k % len == 0)    return head;

        //链表尾部接到头部
        last->next = head;
        k %= len;
        p = head;

        //找到链表的len-k处断开即可
        while(len - k){
            last = p;
            p = p->next;
            --len;
        }
        last->next = NULL;
        return p;
    }

};

