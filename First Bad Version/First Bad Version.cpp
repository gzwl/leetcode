// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

/*
    二分查找即可
*/
class Solution {
public:
    int firstBadVersion(int n) {
        unsigned lhs = 1,rhs = n + 1;
        while(rhs > lhs){
            unsigned mid = lhs + (rhs - lhs) / 2;
            if(isBadVersion(mid))   rhs = mid;
            else    lhs = mid + 1;
        }
        return rhs;
    }
};

