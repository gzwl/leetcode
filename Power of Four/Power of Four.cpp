/*
    首先如果num是4的幂，那一定是2的幂，那我们可以先通过(num & num - 1) == 0来判断（见power of two)

    然后我们知道a^n-1 = (a-1)(a^(n-1) + a^(n-2) +....+ a + 1)(这个可以用数学归纳法或等比数列来证)

    因此4^n-1一定能被3整除，而2*4^n-1 = 2*(4^n-1)+1一定不能被3整除

    所以我们只要再判断(num-1) % 3 == 0就能区别出num是4的幂还是只是2的幂

*/


class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num & num - 1) == 0 && (num - 1) % 3 == 0;
    }
};

