//a simple dp ，dp[i] means the most profit you can get at ith house

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


