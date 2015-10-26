/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /*
    首先找到第一个大于等于x的那个节点large
    然后将large后面小于x的节点插到large前面就可以了
    time O(n)   space O(1)
*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *large = head,*large_prev = NULL;

        //找到第一个大于等于x的那个节点large
        while(large && large->val < x){
            large_prev = large;
            large = large->next;
        }

        //将large后面小于x的节点插到large前面，注意large为head的情况
        if(large){
            ListNode *small = large->next,*small_prev = large;
            while(small){
                while(small && small->val < x){
                    small_prev->next = small->next;
                    small->next = large;
                    if(large_prev)  large_prev->next = small;
                    else    head = small;
                    large_prev = small;
                    small = small_prev->next;
                }
                small_prev = small;
                if(small)   small = small->next;
            }
        }
        return head;
    }
};

