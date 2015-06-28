class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n){           //当n == 0时就没有1了
            n &= (n - 1);   //这里实际上是把n最低一位的1给变成0了
            res++;
        }
        return res;
    }
};

