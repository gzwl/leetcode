/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /* 删除链表中的一个点，但只给了你这个点的指针
    因为一定不是尾部的点
    所以我们就把当前点变成下一个点，然后把下一个点删掉
*/
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

