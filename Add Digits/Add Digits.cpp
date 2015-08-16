/*
    给你一个数，然后不断把这个数的每一位加起来成为一个新的数
    不断循环直到最后只剩一位数，问你这个数字是几
    这道题有一个直接的结论，详见代码
    具体证明可以看 https://en.wikipedia.org/wiki/Digital_root

*/

class Solution {
public:
    int addDigits(int num) {
        if(num == 0)    return 0;
        else if(num % 9)      return num % 9;
        else    return 9;
    }
};

