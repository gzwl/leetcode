/*
    我们假设这n个数字的下标为1~n
    用dp[i][j]表示下标 i < slot < j 的这段数字消去后所能取的最大值，那么答案就是dp[0][n+1]
    于是转移方程为dp[i][j] = max(dp[i][j] , dp[i][k] + dp[k][j] + nums[i-1] * nums[j-1] * nums[k-1])
    time O(n^3)
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int **dp = new int*[nums.size()+2];
        for(int i = 0;i < nums.size() + 2;i++)  dp[i] = new int[nums.size()+2];

        //初始化
        for(int i = 0;i <= nums.size();i++)     dp[i][i+1] = 0;

        //状态转移
        for(int len = 1;len <= nums.size();len++) {
            for(int lhs = 0;lhs + len + 1 <= nums.size() + 1;lhs++) {
                int rhs = lhs + len + 1;
                dp[lhs][rhs] = 0;
                for(int i = lhs + 1;i < rhs;i++)
                    dp[lhs][rhs] = max(dp[lhs][rhs],dp[lhs][i] + dp[i][rhs] + (lhs == 0 ? 1 : nums[lhs-1]) *
                                        (rhs == nums.size() + 1 ? 1 : nums[rhs-1]) * nums[i-1]
                                      );
            }
        }

        int res = dp[0][nums.size()+1];

        for(int i = 0;i < nums.size() + 2;i++)  delete[] dp[i];
        delete[] dp;

        return res;
    }
};

