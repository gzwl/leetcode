/*
    判断一个数是不是只有2,3,5这3个素因子
    方法很简单,把这3个因子都除去,看看最后是不是1即可
*/
class Solution {
public:
    bool isUgly(int num) {
        while(num && num % 2 == 0)   num /= 2;
        while(num && num % 3 == 0)   num /= 3;
        while(num && num % 5 == 0)   num /= 5;
        return num == 1;
    }
};

