/*
    我们用dp[i][j]表示以点(i,j)为右下角所能围成的最大正方形
    然后维护点(i,j)横向和纵向的最大长度sx和sy
    那么就可以进行通过dp[i-1][j-1]转移到dp[i][j]了
    time O(nm),space O(nm)
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(!n)  return 0;
        int m = matrix[0].size();
        if(!m)  return 0;

        //初始化
        int *sy = new int[m];
        int** dp = new int*[n];
        int res = 0;
        for(int i = 0;i < n;i++)    dp[i] = new int[m];
        memset(sy,0,sizeof(int)*m);

        //dp
        for(int i = 0;i < n;i++){
            int sx = 0;
            for(int j = 0;j < m;j++) {
                //状态转移
                if(matrix[i][j] == '1') {
                    ++sx;++sy[j];
                    if(i > 0 && j > 0) {
                        int len = sqrt(dp[i-1][j-1] + 0.5);
                        int edge = min(len + 1,min(sx,sy[j]));
                        dp[i][j] = edge * edge;
                        res = max(res,dp[i][j]);
                    }
                    else {
                        dp[i][j] = 1;
                        res = max(res,1);
                    }
                }
                else {
                    sx = 0;sy[j] = 0;
                    dp[i][j] = 0;
                }
            }
        }

        delete [] sy;
        for(int i = 0;i < n;i++)    delete [] dp[i];
        delete [] dp;
        return res;
    }
};

