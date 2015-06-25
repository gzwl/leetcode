/*
    可以用二分，但牛顿迭代法要更快
    这个算法不难，就是不断用(x,f(x))的切线来逼近方程x^2-a=0的根。根号a实际上就是x^2-a=0的一个正实根
    f(x)=x^2-a的导数是2x，那么函数上任一点(x,f(x))处的切线斜率是2x。
    那么，x-f(x)/(2x)就是一个比x更接近的近似值（更靠近零点）。
    代入f(x)=x^2-a得到x-(x^2-a)/(2x)，也就是x/2+a/2x。
*/

class Solution {
public:
    int mySqrt(int x) {
        double res = x;
        while(fabs(res * res - x) > 1e-5){
            res = res / 2 + x / (2 * res);
        }
        return res;
    }
};
