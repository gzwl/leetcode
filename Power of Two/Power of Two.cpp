//当n为正数且二进制表示里面只有一位是1时，就是2的幂次方所得

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)  return false;
        if(n & (n - 1))     return false;   //是否只有一位是1
        return true;
    }
};

