/*
    求n/m，只能用加减法和位运算
    首先我们可以每次减去一个m，直到n < m，这样减了多少次答案就是多少
    但是这样的time是O(n)的
    那么怎么优化呢?
    其实我们可以每次n减去m的2^k倍(保证m*2^k) < n
    然后答案就加上2^k，这样的time是O(logn)的
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        const int MAX_INT = 0x7fffffff;
        //先处理溢出的情况
        if(dividend == (1<<31) && divisor == -1)    return MAX_INT;
        if(divisor == 0)    return MAX_INT;

        //都换成正数
        long long dividend0 = dividend;
        long long divisor0 = divisor;
        bool negative = 0;
        if(dividend0 < 0) {
            negative = !negative;
            dividend0 = -dividend0;
        }
        if(divisor0 < 0) {
            negative = !negative;
            divisor0 = -divisor0;
        }

        //每次减去divisor的2^mul倍
        long long res = 0;
        while(dividend0 >= divisor0) {
            long long tmp = divisor0;
            long long mul = 1;
            while(dividend0 >= tmp) {
                tmp <<= 1;
                mul <<= 1;
            }
            res += mul >> 1;
            dividend0 -= tmp >> 1;
        }
        if(negative)    res = -res;
        return res;
    }
};

