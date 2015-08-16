/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == NULL)    return res;
        string s;
        dfs(res,s,root);
        return res;
    }
    void dfs(vector<string>& res,string s,TreeNode* ptr){
        if(ptr->left == NULL && ptr->right == NULL){
            s += (char)('0' + ptr->val);
            res.push_back(res);
            return ;
        }
        else{
            s += (char)('0' + ptr->val);
            s += '->';
            if(ptr->left)   dfs(res,s,ptr->left);
            if(ptr->right)      dfs(res,s,ptr->right);
        }
    }
};

