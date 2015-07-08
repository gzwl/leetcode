class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)  return 1;
        else{
            double tmp = myPow(x,n/2);
            tmp *= tmp;
            if(n % 2){
                if(n > 0)   tmp *= x;
                else        tmp /= x;
            }
            return tmp;
        }
    }
};

