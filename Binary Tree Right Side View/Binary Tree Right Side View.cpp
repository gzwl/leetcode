/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //bfs
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if(root)    q.push(root);
        while(q.size()){
            TreeNode *p = q.front();    //每次取出最右边的点加入res
            res.push_back(p->val);
            int cnt = q.size();
            while(cnt--){       //清除这一层的点，并把下一层的点从右到左加入队列
                p = q.front();
                q.pop();
                if(p->right)    q.push(p->right);
                if(p->left)     q.push(p->left);
            }
        }
        return res;
    }
};

