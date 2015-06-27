/*
    dfs
    一共有n层，于是我们排序后暴力枚举每层的元素
    在第i层，我们用s来记录前面i-1层使用过的元素
    最后到第n层时我们就能得到一个解
*/

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        int n = num.size();
        if(!n)  return res;
        sort(num.begin(),num.end());
        vector<int> tmp;
        dfs(res,num,tmp,0,0,n);
        return res;
    }
    void dfs(vector<vector<int> > &res,vector<int> &num,vector<int> tmp,int cur,int s,int n)
    {
        if(cur == n){       //第n层  得到一个解
            res.push_back(tmp);return ;
        }
        for(int i = 0;i < n;i++){
            if(s & (1 << i))    continue;         //已经被使用过的元素不能再被使用
            else{
                if(tmp.size() != cur + 1)     tmp.push_back(num[i]);
                else    tmp[cur] = num[i];
                dfs(res,num,tmp,cur + 1,(1 << i) | s,n);
            }
        }
    }
};

