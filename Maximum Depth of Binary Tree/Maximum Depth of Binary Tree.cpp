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
    int maxDepth(TreeNode *root) {
        if(root == NULL)    return 0;
        else{
            int depth = max(maxDepth(root->left),maxDepth(root->right));
            return depth + 1;
        }
    }
};
