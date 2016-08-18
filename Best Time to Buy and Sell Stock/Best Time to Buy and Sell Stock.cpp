/*
    因为只能进行一次交易，所以对于每个价格，我们只要维护它前面价格中的最小值即可

    答案就是所有当前价格减去它前面价格最小值后的最大差值

    time O(n), space O(1)
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = 0x7fffffff;
        int result = 0;
        for(int i = 0;i < prices.size();i++) {
            result = max(result, prices[i] - minPrice);
            //维护一个最小值
            minPrice = min(minPrice, prices[i]);
        }
        return result;
    }
};

