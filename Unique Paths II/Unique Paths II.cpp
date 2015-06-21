class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int n = obstacleGrid.size();
        int m = n ? obstacleGrid[0].size() : 0;
        if(!n)  return 0;
        int **dp = new int*[n];
        for(int i = 0;i < n;i++)    dp[i] = new int[m];     //dp[i][j]表示到达(i,j)的方法数
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(i == 0 && j == 0){
                    if(obstacleGrid[0][0] == 0)     dp[i][j] = 1;
                    else    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = 0;
                    if(obstacleGrid[i][j])      continue;
                    if(i > 0 && obstacleGrid[i-1][j] == 0)  dp[i][j] += dp[i-1][j];
                    if(j > 0 && obstacleGrid[i][j-1] == 0)  dp[i][j] += dp[i][j-1];
                }
            }
        }
        int res = dp[n-1][m-1];
        for(int i = 0;i < n;i++)    delete [] dp[i];
        delete [] dp;
        return res;
    }
};
