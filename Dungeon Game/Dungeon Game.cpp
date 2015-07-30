/*
    用dp[i][j]表示从(i,j)到(n-1,m-1)时在(i,j)上至少需要多少HP
    那么转移方程就是 dp[i][j] = max(min(dp[i+1][j],dp[i][j+1]) - dungeon[i][j],1);
    注意在每个点上至少都要有1的生命值
    时间复杂度  O(nm)
    空间复杂度  O(nm)
*/
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        int **dp = new int*[n];
        for(int i = 0;i < n;i++)    dp[i] = new int[m];
        for(int i = n - 1;i >= 0;i--){
            for(int j = m - 1;j >= 0;j--){
                if(i != n - 1 && j != m - 1)    dp[i][j] = max(min(dp[i+1][j],dp[i][j+1]) - dungeon[i][j],1);
                else if(i != n - 1)     dp[i][j] = max(dp[i+1][j] - dungeon[i][j],1);
                else if(j != m - 1)     dp[i][j] = max(dp[i][j+1] - dungeon[i][j],1);
                else    dp[i][j] = max(1 - dungeon[i][j],1);
            }
        }
        int res = dp[0][0];
        for(int i = 0;i < n;i++)    delete [] dp[i];
        delete [] dp;
        return res;
    }
};

