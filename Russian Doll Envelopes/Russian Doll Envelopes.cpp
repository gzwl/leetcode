/*
    这道题其实就是求二维的严格最长上升子序列长度

    首先我们想到可以将envelop先按照w从小到大排列，相同w的h从小到大排列，然后在h这一维上求最长上升子序列

    但是这样有一个问题，就是相同w的h会影响

    比如说(2,3)(3,5),(3,7)这两个点，我们这样直接求最长上升子序列的结果会是3，就得不到正确结果2了

    所以正确做法是将envelop先按照w从小到大排列，相同w的h从大到小排列，然后在h这一维上求最长上升子序列

    这样相同w的h就不会影响了

    time O(nlogn) , space O(n)
*/

class Solution {
private:
    const static int maxValue = 0x7fffffff;

    //将envelop先按照w从小到大排列，相同w的h从大到小排列
    static bool cmp(pair<int,int> lhs,pair<int,int> rhs) {
        if(lhs.first != rhs.first)  return lhs.first < rhs.first;
        else    return lhs.second > rhs.second;
    }

public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        int *dp = new int[envelopes.size()];
        int result = 0;
        for(int i = 0;i < envelopes.size();i++) {
            dp[i] = maxValue;
            int *cur = lower_bound(dp, dp + i + 1, envelopes[i].second);
            *cur = envelopes[i].second;
        }
        for(int i = envelopes.size() - 1; i >= 0; i--) {
            if(dp[i] != maxValue) {
                result = i + 1;
                break;
            }
        }
        delete [] dp;
        return result;
    }
};

