/*
    做法很直接了，扫一遍就可以了
    时间复杂度O(n)
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int lhs = 0,rhs = 0;
        vector<string> res;
        while(rhs < nums.size()){
            while(rhs < nums.size() && nums[rhs] - nums[lhs] == rhs - lhs)  rhs++;
            char tmp[100] = {0};
            if(lhs == rhs - 1)  sprintf(tmp,"%d",nums[lhs]);
            else    sprintf(tmp,"%d->%d",nums[lhs],nums[rhs - 1]);
            string s;
            int cnt = 0;
            while(tmp[cnt]) s += tmp[cnt++];
            lhs = rhs;
            res.push_back(s);
        }
        return res;
    }
};


