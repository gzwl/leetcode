/*
    这道题可以用埃氏筛法来做
    简单来讲就是如果我们找到一个素数，那么他的倍数一定就是合数
    那么我们在找到一个素数之后就把它的倍数都筛掉就可以了
*/

class Solution {
public:
    int countPrimes(int n) {
        typedef long long ll;
        int *isprime = new int[n + 1];
        for(int i = 2;i < n;i++)   isprime[i] = 1;
        int res = 0;
        for(int i = 2;i < n;i++){
            if(isprime[i]){         //找到一个素数i
                res++;
                for(ll j = (ll)i * i;j <= n;j += i){    //把i的倍数都丢掉，注意从i*i开始，因为2*i ~ (i-1)*i其实之前都被筛掉了
                    isprime[j] = 0;
                }
            }
        }
        delete [] isprime;
        return res;
    }
};

