/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /*
    因为是二叉搜索树，所以如果p和q分别在当前所搜子树的root的两边，那么root就是答案
    如果p和q都大于root就搜root的右子树
    如果p和q都小于root就搜root的左子树
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q)  return root;
        int flag1 = p->val > root->val  ?   1 : 0;
        int flag2 = q->val > root->val  ?   1 : 0;
        if(flag1 ^ flag2)   return root;
        else if(flag1 && flag2)     return lowestCommonAncestor(root->right,p,q);
        else    return lowestCommonAncestor(root->left,p,q);
    }
};
