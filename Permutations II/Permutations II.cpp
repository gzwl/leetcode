/*
    和I的解法一样
    不过要注意处理重复的解
*/



class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        int n=num.size();
        if(!n)  return res;
        sort(num.begin(),num.end());
        vector<int> tmp;
        dfs(res,num,tmp,0,0,n);
        return res;
    }
    void dfs(vector<vector<int> > &res,vector<int> &num,vector<int> tmp,int cur,int s,int n)
    {
        if(cur == n){
            res.push_back(tmp);return ;
        }
        int prev = -1;
        for(int i = 0;i < n;i++)
        {
            if(s & (1 << i))    continue;
            else if(prev != -1 && num[i] == num[prev])      continue;//处理重复的解，当前层已经处理过的元素以后要跳过
            else{
                prev = i;
                if(tmp.size() != cur + 1)     tmp.push_back(num[i]);
                else    tmp[cur] = num[i];
                dfs(res,num,tmp,cur + 1,(1 << i) | s,n);
            }
        }
    }
};
