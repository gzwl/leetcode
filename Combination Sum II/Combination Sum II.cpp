/*
    和I一样，暴搜就能过了
*/


class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > res;
        vector<int> tmp;
        dfs(0,0,candidates,tmp,res,target);
        return res;
    }
    void dfs(int cur,int depth,vector<int> &a,vector<int> tmp,vector<vector<int> > &res,int target)
    {
        if(target == 0){
            res.push_back(tmp);return ;
        }
        for(int i = cur;i < a.size();i++){
            //两个剪枝，当前数大于目标值或当前数在该层已经被搜过要跳过
            if(target - a[i] < 0)   break;
            if(i != cur && a[i] == a[i-1])  continue;
            if(tmp.size() == depth)     tmp.push_back(a[i]);
            else    tmp[depth] = a[i];
            dfs(i + 1,depth + 1,a,tmp,res,target - a[i]);   //避免重复所以这里是i + 1
        }
    }
};

