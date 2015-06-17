//很简单的动态规划，dp[i]表示到第i间房子能获得的最大利益

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int *dp = new int[n];
        int res = 0;
        for(int i = 0;i < n; i++){
            if(i == 0){
                dp[i] = nums[i];
            }
            else if(i == 1){
                dp[i] = max(nums[i],dp[i-1]);
            }
            else{
                dp[i] = max(dp[i-1],dp[i-2] + nums[i]);
            }
            res = max(res,dp[i]);
        }
        delete [] dp;
        return res;
    }
};
