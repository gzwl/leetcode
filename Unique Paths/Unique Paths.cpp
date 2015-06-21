class Solution {
public:
    int uniquePaths(int m, int n) {
        if(!m || !n)    return 0;
        int **dp = new int*[m];         //dp[i][j]表示到达(i,j)的方法数
        for(int i = 0;i < m;i++){
            dp[i] = new int[n];
        }
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(i == 0 && j == 0)    dp[i][j] = 1;
                else if(i == 0)     dp[i][j] = dp[i][j-1];
                else if(j == 0)     dp[i][j] = dp[i-1][j];
                else    dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        int res = dp[m-1][n-1];
        for(int i = 0;i < m;i++)    delete [] dp[i];
        delete [] dp;
        return res;
    }
};
