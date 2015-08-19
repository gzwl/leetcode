class Solution {
public:
    int nthUglyNumber(int n) {
        --n;
        int a = n / 3;
        int b = n % 3;
        int res = 1;
        res *= pow(2,a) * pow(3,a) * pow(5,a);
        if(b == 1)   res *= 2;
        if(b == 2)   res *= 3;
        return res;
    }
    int pow(int x,int y)    //快速冥求x^y
    {
        if(y == 0)  return 1;
        int tmp = pow(x,y/2);
        if(y % 2)   return tmp * tmp * x;
        else    return tmp * tmp;
    }
};

