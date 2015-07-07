class Solution {
public:
    bool isHappy(int n) {
        map<int,int> mapint;
        while(n != 1){
            if(mapint[n])   return false;   //出现循环就不是
            mapint[n] = 1;
            int sum = 0;
            while(n){
                sum += (n%10) * (n%10);
                n /= 10;
            }
            n = sum;
        }
        return true;
    }
};
