/*
    对于这个问题,我们可以用dp[i]来表示当和为i时的组合数

    然后我们可以通过和为i的组合数递推出和大于i的组合数来

    time O(n*target)，space O(target)

*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int* dp = new int[target + 1];
        dp[0] = 1;
        for(int i = 1;i <= target;i++) {
            dp[i] = 0;
            for(int j = 0;j < nums.size();j++) {
                if(i - nums[j] >= 0)
                    //状态转移
                    dp[i] += dp[i - nums[j]];
            }
        }

        //答案
        int result = dp[target];
        delete [] dp;
        return result;
    }
};

