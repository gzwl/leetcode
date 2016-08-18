/*
    和I不同，这次我们可以做任意次交易

    因此我们维护两个值maxBuyValue和maxSellValue

    maxBuyValue表示前面最后一次买操作所能取得的最大利润

    maxSellValue表示前面最后一次卖操作所能取得的最大利润

    那么最后答案就是maxSellValue

    time O(n) ,space O(1)

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxBuyValue = 0x80000000;
        int maxSellValue = 0;
        for(int i = 0;i < prices.size();i++) {
            //状态转移，对于每个价格，我们分别求出当前执行买和卖所能得到的最大利润
            int buyValue, sellValue;
            buyValue = max(-prices[i], maxSellValue - prices[i]);
            sellValue = maxBuyValue + prices[i];
            maxSellValue = max(maxSellValue, sellValue);
            maxBuyValue = max(maxBuyValue, buyValue);
        }
        return maxSellValue;
    }
};

