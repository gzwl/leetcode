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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if(root == NULL)    return res;
        stack<TreeNode *> s[2];
        int dep = 0;
        s[dep].push(root);
        while(!s[dep].empty()){
            vector<int> tmp;
            while(!s[dep].empty()){
                TreeNode *p = s[dep].top();
                s[dep].pop();
                tmp.push_back(p->val);
                if(!dep){
                    if(p->left)     s[dep^1].push(p->left);
                    if(p->right)    s[dep^1].push(p->right);
                }
                else{
                    if(p->right)    s[dep^1].push(p->right);
                    if(p->left)     s[dep^1].push(p->left);
                }
            }
            res.push_back(tmp);
            dep ^= 1;
        }
        return res;
    }
};

