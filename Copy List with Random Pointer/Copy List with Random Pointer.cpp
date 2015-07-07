/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 //时间复杂度O(n)
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *p = head;
        /*
            首先，在原来链表的每个节点后面生成一个新的节点
            假设原来是1->2->3->4->5->NULL
            变成1->1'->2->2'->3->3'->4->4'->5->5'->NULL
        */
        while(p){
            RandomListNode *q = new RandomListNode(p->label);
            q->next = p->next;
            p->next = q;
            p = q->next;
        }
        /*
            然后，因为每个老节点后面都有一个新节点，那么就可以借助这种关系求出每个新节点的random
            即新节点的random = 老节点的random->next
        */
        RandomListNode *res = head ? head->next : NULL;
        p = head;
        while(p){
            RandomListNode *q = p->next;
            if(p->random == NULL)   q->random = NULL;
            else{
                q->random = p->random->next;
            }
            p = q->next;
        }
        /*
            最后，将新老节点分离，就可以得出一个新链表了
            即1->1'->2->2'->3->3'->4->4'->5->5'->NULL
            分离为1->2->3->4->5->NULL和1'->2'->3'->4'->5'->NULL
        */
        p = head;
        while(p){
            RandomListNode *q = p->next;
            p->next = q->next;
            if(q->next)     q->next = q->next->next;
            p = p->next;
        }
        return res;
    }
};

