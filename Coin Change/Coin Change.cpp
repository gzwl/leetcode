/*
    我们可以用sum[i]表示兑换到i块钱所用到的最少硬币数
    那么有转移方程sum[i] = min(sum[i],sum[i-coins[j]] + 1);
    最后sum[amount]就是答案了
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int *sum = new int[amount + 1];

        //初始化，0块钱需要0个
        sum[0] = 0;

        //对于每个i块钱，求出最小硬币sum[i]
        for(int i = 1;i <= amount;i++) {
            //这里先初始化成一个不可能的数，因为最多amount个
            sum[i] = amount + 1;
            for(int j = 0;j < coins.size();j++) {
                if(i >= coins[j])
                    sum[i] = min(sum[i],sum[i-coins[j]] + 1);
            }
        }
        int res = sum[amount];
        delete [] sum;
        return res == amount + 1 ? -1 : res; //如果是不可能的数，返回-1
    }
};

