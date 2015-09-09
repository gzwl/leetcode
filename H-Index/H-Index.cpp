/*
    首先对citations进行排序，然后二分枚举答案h
    time O(nlogn + logn*logm)
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int n = citations.size();
        if(n == 0)  return 0;

        //二分枚举答案h
        unsigned lhs = 0,rhs = citations[n-1] + 1;
        unsigned res = 0;
        while(rhs > lhs){
            int mid = lhs + (rhs - lhs) / 2;
            if(citations.end() - lower_bound(citations.begin(),citations.end(),mid) >= mid){
                res = mid;
                lhs = mid + 1;
            }
            else    rhs = mid;
        }
        return res;
    }
};
