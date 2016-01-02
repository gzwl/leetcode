/*
    最长上升子序列，朴素的做法是用dp[i]表示以下标为i的数为尾的最长上升子序列的长度，然后 time O(n^2)可以做
    更好的做法是O(n)扫一遍数组，用dp数组维护当前的最长上升子序列
    然后对于扫到的每个数，用二分O(logn)来插入dp数组以维护这个最长上升子序列
    于是总的 time O(nlogn)
    详见代码，这样更好理解
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        int *dp = new int[nums.size()];
        int res = 1;
        dp[0] = nums[0];

        //二分插入
        for(int i = 1;i < nums.size();i++) {
            int index = lower_bound(dp,dp + res,nums[i]) - dp;

            //当前数比序列中的所有数都大，插入到末尾，子序列长度增加
            if(index == res)    dp[res++] = nums[i];

            //不是最大的，替换掉大于等于它的第一个数，不会影响之前的结果，同时使得整个上升子序列尽可能小
            else    dp[index] = nums[i];
        }
        delete[] dp;
        return res;
    }
};
