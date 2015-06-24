//和I相同的做法，只是要分取第一个和不取第一个两种情况来讨论

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return nums[0];
        int *dp = new int[n];
        int res = 0;
        for(int i = 0;i < n - 1; i++){
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
        for(int i = 1;i < n; i++){
            if(i == 1){
                dp[i] = nums[i];
            }
            else if(i == 2){
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

