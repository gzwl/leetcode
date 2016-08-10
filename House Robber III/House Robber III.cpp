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
    首先我们知道，每一个点有且只有取和不取两种情况

    那么我们可以做一遍dfs，对于每一个点，我们返回两个值

    分别是在取它和不取它的情况下，以它为根节点的子树所能取得的最大值

    然后可以通过这两个值进行状态转移，见代码注释

    这样答案就是根节点取和不取的两个最大值中最大的那一个

 */

class Solution {
public:
    int rob(TreeNode* root) {
        pair<int, int> result = findMaxValue(root);
        return max(result.first, result.second);
    }

    pair<int, int> findMaxValue(TreeNode* node) {
        if(node == NULL)    return make_pair(0 ,0);
        pair<int, int> result1 = findMaxValue(node->left);
        pair<int, int> result2 = findMaxValue(node->right);

        //不取该点的最大值=max(取左儿子的最大值，不取左儿子的最大值)+max(取右儿子的最大值，不取右儿子的最大值)
        int maxNotGetValue = max(result1.first, result1.second) + max(result2.first, result2.second);

        //取该点的最大值=不取左儿子的最大值+不取右儿子的最大值+该点自己的值
        int maxGetValue = result1.second + result2.second + node->val;
        return make_pair(maxGetValue, maxNotGetValue);
    }

};
