class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int n = matrix.size();
        int m = n ? matrix[0].size() : 0;
        if(!n || !m)    return 0;
        int *dp = new int[m];
        int *rl = new int[m];
        int *rr = new int[m];
        int *s = new int[m];
        int res = 0;
        for(int j = 0;j < m;j++)    dp[j] = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(matrix[i][j] == '1')     dp[j]++;    //at(i,j),the sum of consecutive '1' is dp[j]
                else    dp[j] = 0;
            }
            int top = 0;
            for(int j = 0;j < m;j++){
                while(top && dp[j] < dp[s[top-1]])    top--;
                if(!top)    rl[j] = 0;
                else if(dp[s[top-1]] == dp[j])  rl[j] = rl[s[top-1]];
                else    rl[j] = s[top-1] + 1;
                s[top++] = j;
            }
            top = 0;
            for(int j = m - 1;j >= 0;j--){
                while(top && dp[j] < dp[s[top-1]])    top--;
                if(!top)    rr[j] = m - 1;
                else if(dp[s[top-1]] == dp[j])  rr[j] = rr[s[top-1]];
                else    rr[j] = s[top-1] - 1;
                s[top++] = j;
            }
            for(int j = 0;j < m;j++){
                res = max(res,dp[j] * (rr[j] - rl[j] + 1));
            }
        }
        delete [] dp;
        delete [] rl;
        delete [] rr;
        delete [] s;
        return res;
    }
};
