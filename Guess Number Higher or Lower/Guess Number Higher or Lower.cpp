// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0

/*
    一个很裸的二分搜索，注意不要死循环和溢出即可
*/
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int lhs = 1, rhs = n;
        while(rhs >= lhs) {
            int mid = lhs + (rhs - lhs) / 2;
            int result = guess(mid);
            if(result > 0)  lhs = mid + 1;
            else if(result < 0) rhs = mid - 1;
            else return mid;
        }
        return -1;
    }
};

