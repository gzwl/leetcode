class Solution {
public:
    int climbStairs(int n) {
        int *dp = new int[n+1];     //dp[i]是到达第i个阶梯的方法数
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        int res = dp[n];
        delete [] dp;
        return res;
    }
};


