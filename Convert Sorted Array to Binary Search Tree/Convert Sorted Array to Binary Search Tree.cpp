/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /*
    将排好序的数组转换为平衡二叉树
    假设当前处理的区间为[lhs,rhs)
    那么他们构成树的根就是mid
    左子树由[lhs,mid)构成,右子树由[mid + 1,rhs)构成
    这样递归构造就可以了
*/
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        TreeNode *root = NULL;
        build(num,root,num.size() / 2,0,num.size());
        return root;
    }
    void build(vector<int> &num,TreeNode* &p,int id,int lhs,int rhs)
    {
        if(id < lhs || id >= rhs)   return ;
        p = new TreeNode(num[id]);
        TreeNode *pl = NULL,*pr = NULL;
        build(num,pl,(lhs + id) / 2,lhs,id);
        build(num,pr,(id + 1 + rhs) / 2,id + 1,rhs);
        p->left = pl;
        p->right = pr;
    }
};
