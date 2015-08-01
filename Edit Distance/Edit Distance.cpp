/*
    动态规划求最短编辑距离
    用dp[i][j]表示word1的前i项变得和word2的前j项一样需要多少步
    具体转移方程请看下面
    时间复杂度为O(nm)
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int **dp = new int*[n+1];
        for(int i = 0;i < n + 1;i++)    dp[i] = new int[m+1];
        //dp边界初始化
        for(int i = 0;i < n + 1;i++)    dp[i][0] = i;
        for(int i = 0;i < m + 1;i++)    dp[0][i] = i;
        //转移方程
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(word1[i] == word2[j])    dp[i+1][j+1] = dp[i][j];
                else{
                    dp[i+1][j+1] = min(dp[i][j+1],min(dp[i+1][j],dp[i][j])) + 1;
                }
            }
        }
        int res = dp[n][m];
        for(int i = 0;i <= n;i++)    delete [] dp[i];
        delete [] dp;
        return res;
    }
};

