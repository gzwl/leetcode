/*
    求从1到n中出现了多少次数字1
    这是一道数位dp，首先我们先预处理出dp和ten
    dp[k]表示k+1位有多少个1，比如dp[0]表示0~9有多少1，dp[1]表示0~99有多少1，依次类推
    ten[k]表示10^k
    然后对于给定的n，我们把它的每个十进制位分离出来，记在bit中
    接着我们开始从高位往低位递推，递推方法见代码
*/

class Solution {
private:
    int dp[10];
    int ten[10];
public:
    Solution() {
        //预处理
        int tmp = 10;
        dp[0] = 1;
        ten[0] = 1;
        for(int i = 1;i < 10;i++) {
            dp[i] = dp[i-1] * 10 + tmp;
            ten[i] = tmp;
            tmp *= 10;
        }
    }
    int countDigitOne(int n) {
        if(n < 0)   return 0;
        int bit[10];
        int top = 0;
        //十进制位分离出来
        while(n) {
            bit[top++] = n % 10;
            n /= 10;
        }
        //res表示结果
        int res = 0;

        //sum表示比i高的位中有多少位是1
        int sum = 0;

        //从高位到低位扫描
        for(int i = top - 1;i >=0 ;i--) {
        /* 为了便于理解,我们假设给的n是21354
           然后我们现在扫到了3，那么现在0~21000已经统计完了
           我们开始统计21000~21300
        */

            res += bit[i] * ten[i] * sum;       //首先要加上300个1,因为3的前面有一位是1
            if(i)   res += bit[i] * dp[i-1] ;   //然后加上3*(0~99中出现1的个数)
            if(bit[i] > 1)  res += ten[i];      //然后加上211xx中的这个1，因为第二步没有统计
            if(bit[i] == 1) {                   //如果当前位是1，还要加一个
                sum++;
                res++;
            }
        }
        return res;
    }
};

