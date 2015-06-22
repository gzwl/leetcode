class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > res;
        for(int i = 0;i <= nums.size();i++){
            if(i == nums.size()){
                dfs(i,nums,res,0);
                continue;
            }
            if(i && nums[i] == nums[i-1])   continue;
            dfs(i + 1,nums,res,1 << i);
        }
        return res;
    }
    void dfs(int cur,vector<int>& nums,vector<vector<int>>& res,int S)  //S是一个集合，表示取了哪些数
    {
        if(cur == nums.size()){
            vector<int> tmp;
            for(int i = 0;i < nums.size();i++){
                if(S & (1 << i)){
                    tmp.push_back(nums[i]);
                }
            }
            res.push_back(tmp);
            return ;
        }
        for(int i = cur;i <= nums.size();i++){
            if(i == nums.size()){
                dfs(i,nums,res,S);
                continue;
            }
            if(i != cur && nums[i] == nums[i-1])    continue;
            dfs(i + 1,nums,res,S | (1 << i));
        }
    }
};
