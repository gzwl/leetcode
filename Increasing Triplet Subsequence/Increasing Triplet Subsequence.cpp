/*
    这道题就是最长上升子序列长度为3的特殊情况，所以我们用最长上升子序列的做法做即可

    time O(n), space O(1)

    另外我们可以推广到当长度为k时，复杂度为 time O(nlogk) , space O(k)
*/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int dp[3];
        for(int i = 0;i < 3;i++)    dp[i] = 0x7fffffff;
        for(int i = 0;i < nums.size();i++) {
            int index = lower_bound(dp, dp + 3, nums[i]) - dp;
            if(index == 2)  return true;
            dp[index] = nums[i];
        }
        return false;
    }
};

