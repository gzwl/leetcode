/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //很简单了，就dfs
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if(root == NULL)    return 0;
        int res = 0;
        dfs(root,0,res);
        return res;
    }
    void dfs(TreeNode *p,int sum,int &res)
    {
        if(p->left == NULL && p->right == NULL)     res += sum * 10 + p->val;
        if(p->left)     dfs(p->left,sum * 10 + p->val,res);
        if(p->right)    dfs(p->right,sum * 10 + p->val,res);
    }
};
