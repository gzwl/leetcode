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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> s;
        s.push(root);
        while(s.size()){
            TreeNode *p = s.top();
            s.pop();
            while(p){
                if(p->right)    s.push(p->right);
                res.push_back(p->val);
                p = p->left;
            }
        }
        return res;
    }
};

