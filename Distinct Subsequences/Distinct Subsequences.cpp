/*
    用dp[i][j]表示t的前i长度部分在s的前j长度部分出现的次数
    然后转移方程就是:
    if(t[i-1] == s[j-1])    dp[i][j] = dp[i][j-1];
    else                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = t.size();
        int m = s.size();
        int **dp = new int*[n+1];
        for(int i = 0;i <= n;i++)    dp[i] = new int[m+1];
        //初始化dp[0][i] = 1，空串出现个数为1次
        for(int i = 0;i <= m;i++)    dp[0][i] = 1;
        for(int i = 1;i <= n;i++){
            dp[i][0] = 0;
            for(int j = 1;j <= m;j++){
                dp[i][j] = dp[i][j-1];
                if(t[i-1] == s[j-1]){
                    dp[i][j] += dp[i-1][j-1];
                }
            }
        }
        int res = dp[n][m];
        for(int i = 0;i <= n;i++)    delete [] dp[i];
        delete [] dp;
        return res;
    }
};

