/*
    维护一个区间的左端点lhs和右端点rhs
    如果没有重复的元素就不断从右边放入元素
    否则就从左端点不断删除元素
    时间复杂度O(n)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt[300] = {0};
        int lhs = 0,rhs = 0;
        int res = 0;
        while(rhs < s.size()){
            while(cnt[s[rhs]]){
                cnt[s[lhs]]--;
                lhs++;
            }
            cnt[s[rhs]] = 1;
            res = max(res,rhs - lhs + 1);
            rhs++;
        }
        return res;
    }
};

