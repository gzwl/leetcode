/*
    和I一样，二分枚举答案h
    time O(logn)
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n == 0)  return 0;
        int lhs = 1,rhs = n + 1;
        int res = 0;
        while(rhs > lhs){
            int mid = lhs + (rhs - lhs) / 2;
            if(citations[n - mid] >= mid){
                res = mid;
                lhs = mid + 1;
            }
            else    rhs = mid;
        }
        return res;
    }
};

