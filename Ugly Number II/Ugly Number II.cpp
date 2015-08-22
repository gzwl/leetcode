/*
    首先，新的一个ugly number肯定是从较小的ugly number乘以2,3或5得来的
    那么我们维护三个下标id0,id1,id
    则ugly[id0]*2,ugly[id1]*3,ugly[id2]*5的最小值为下一个数
    注意最小值必须大于当前已有ugly number中的最大值，不然就会重复了
    time O(n)
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        typedef long long ll;
        int *ugly = new int[n];
        int id0 = 0,id1 = 0,id2 = 0;
        int cnt = 0;
        ugly[cnt] = 1;
        while(cnt != n - 1){
            //必须大于当前已有ugly number中的最大值，不然就会重复了
            while(ugly[id0] * 2 <= ugly[cnt])   ++id0;
            while(ugly[id1] * 3 <= ugly[cnt])   ++id1;
            while(ugly[id2] * 5 <= ugly[cnt])   ++id2;
            //最小值为下一个数
            int minid = id0,minval = ugly[id0] * 2;
            if(ugly[id1] * 3 < minval){
                minval = ugly[id1] * 3;
                minid = id1;
            }
            if(ugly[id2] * 5 < minval){
                minval = ugly[id2] * 5;
                minid = id2;
            }
            ugly[++cnt] = minval;
            if(minid == id0)    ++id0;
            else if(minid == id1)   ++id1;
            else    ++id2;
        }
        int res = ugly[n-1];
        delete [] ugly;
        return res;
    }
};
