/*
    1.假设有N个元素A到B。
    2.那么根据鸽巢原理，最大差值不会小于ceiling[(B - A) / (N - 1)]。
    3.令bucket（桶）的大小div = ceiling[(B - A) / (N - 1)]，则最多会有(B - A) / div + 1个桶
    4.对于数组中的任意整数K，很容易通过算式slot = (K - A) / div找出其桶的位置，然后维护每一个桶的最大值和最小值
    5.由于同一个桶内的元素之间的差值至多为div - 1，因此最终答案不会从同一个桶中选择。
    6.对于每一个非空的桶p，找出下一个非空的桶q，则q.min - p.max可能就是备选答案。返回所有这些可能值中的最大值。

*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)     return 0;

        //求maxval,minval
        int minval = nums[0],maxval = nums[0];
        for(int i = 1;i < n;i++){
            minval = min(nums[i],minval);
            maxval = max(nums[i],maxval);
        }

        //分桶
        int div;
        if((maxval - minval) % (n - 1) == 0)    div = (maxval - minval) / (n - 1);
        else    div = (maxval - minval) / (n - 1) + 1;
        vector<vector<int>> vec(n);
        for(int i = 0;i < n;i++){
            int slot = (nums[i] - minval) / div;
            if(vec[slot].size() == 0){
                vec[slot].push_back(nums[i]);
                vec[slot].push_back(nums[i]);
            }
            else{
                vec[slot][0] = min(vec[slot][0],nums[i]);
                vec[slot][1] = max(vec[slot][1],nums[i]);
            }
        }

        //从每相邻的两个非空桶中找出结果
        int res = 0;
        int prev = -1;
        for(int i = 0;i < n;i++){
            if(vec[i].size()){
                if(prev != -1)  res = max(res,vec[i][0] - vec[prev][1]);
                prev = i;
            }
        }
        return res;
    }
};

