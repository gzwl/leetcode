/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        int h = hf(root);
        return h != -1 ? true : false;
    }
    int hf(TreeNode *p){
        if(p == NULL)   return 0;
        int lh = hf(p->left);
        int rh = hf(p->right);
        if(lh == -1 || rh == -1 || abs(lh - rh) > 1)    return -1;
        else return 1 + max(lh,rh);
    }
};

