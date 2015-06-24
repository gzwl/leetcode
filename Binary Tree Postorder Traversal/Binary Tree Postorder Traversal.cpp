/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct node
{
    TreeNode *p;
    bool flag;      //flag表示有没有访问过右子树
};
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        TreeNode *p = root;
        stack<node> s;
        while(1){
            while(p){                       //左子树入栈
                s.push((node){p,0});
                p = p->left;
            }
            if(s.empty())   break;
            node u = s.top();s.pop();
            if(u.flag || (u.p)->right == NULL){         //访问节点本身
                res.push_back((u.p)->val);
            }
            else{                           //右子树入栈
                u.flag = 1;
                s.push(u);
                p = (u.p)->right;
            }
        }
        return res;
    }
};

