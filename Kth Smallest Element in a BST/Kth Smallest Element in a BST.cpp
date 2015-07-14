/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //答案就是二叉树中序遍历序列的第k个，这里是非递归做法
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode *p = root;
        int cnt = 0;
        while(p || s.size()){
            while(p){
                s.push(p);
                p = p->left;
            }
            p = s.top();s.pop();
            cnt++;
            if(cnt == k)    return p->val;
            p = p->right;
        }
    }
};

