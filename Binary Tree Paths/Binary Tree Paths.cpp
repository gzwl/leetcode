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
    直接dfs就可以了，把数转化为字符串的时候要注意数不只有一位并且还可能有负数
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
        if(ptr->val == 0)   s += '0';
        else{
            if(ptr->val < 0){
                ptr->val *= -1;
                s += '-';
            }
            string tmp;
            while(ptr->val){
                tmp += ((ptr->val % 10) + '0');
                ptr->val /= 10;
            }
            reverse(tmp.begin(),tmp.end());
            s += tmp;
        }
        if(ptr->left == NULL && ptr->right == NULL){
            res.push_back(s);
            return ;
        }
        else{
            s += '-';
            s += '>';
            if(ptr->left)   dfs(res,s,ptr->left);
            if(ptr->right)      dfs(res,s,ptr->right);
        }
    }
};


