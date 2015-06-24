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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lena = 0,lenb = 0;
        ListNode *pa = headA;
        while(pa){
            lena++;
            pa = pa->next;
        }
        ListNode *pb = headB;
        while(pb){
            lenb++;
            pb = pb->next;
        }
        pa = headA,pb = headB;
        while(lena > lenb){         //把两条链表移到同样长的位置，然后一个一个进行比较就可以了
            pa = pa->next;
            lena--;
        }
        while(lenb > lena){
            pb = pb->next;
            lenb--;
        }
        while(pa && pb){
            if(pa == pb)    return pa;
            else{
                pa = pa->next;
                pb = pb->next;
            }
        }
        return 0;
    }
};
