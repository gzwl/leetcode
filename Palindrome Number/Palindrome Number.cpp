//解法很直接，把x的每一位分离出来，然后进行前后比较就可以了

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)  return false;
        if (x < 10)  return true;
        int tmp = x;
        int len = 0;
        while(tmp){
            tmp /= 10, ++len;
        }
        int left = pow(10, len - 1);
        int right = 1;
        while(left > right){
            if (x / left % 10 != x / right % 10)  return false;
            left /= 10;
            right *= 10;
        }
        return true;
    }
};

