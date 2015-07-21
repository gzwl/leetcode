//因为给的是int,一个简单的方法是转成long long来判断

class Solution {
public:
    int reverse(int x) {
        if(!x)  return 0;
        while(x%10 == 0)     x /= 10;
        long long sum = 0;
        while(x){
            sum = sum * 10 + x % 10;
            x /= 10;
        }
        int res = sum;
        if(res == sum)  return res;
        else    return 0;
    }
};

