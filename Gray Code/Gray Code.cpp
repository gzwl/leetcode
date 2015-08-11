/*
    这道题的难点在于怎么把binary code转化为gray code
    方法就是把binary code 的每一位和比它高一位的那位异或求值即可
    即：grav = (binary >> 1) ^ binary;
    然后依次求出就可以了
    time O(2^n)
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1 << n);
        for(int i = 0;i < (1 << n);i++){
            int bit = (i >> 1) ^ i;
            res[i] = bit;
        }
        return res;
    }
};

