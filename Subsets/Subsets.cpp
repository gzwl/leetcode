class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        int n = S.size();
        sort(S.begin(),S.end());
        vector<vector<int> > res;
        for(int s = 0;s < (1<<n);s++){      //共有2^n个subset，枚举就可以了
            vector<int> tmp;
            for(int i = 0;i < n;i++){
                if(s & (1 << i))    tmp.push_back(S[i]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
