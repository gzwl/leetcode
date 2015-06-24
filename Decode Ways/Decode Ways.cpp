//dp[i]表示到第i个字母时有多少种解法

class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if(!n)  return 0;
        int *dp = new int[n];
        if(s[0] != '0')     dp[0] = 1;
        else    dp[0] = 0;
        for(int i = 1; i < n; i++){
            dp[i] = 0;
            if(s[i] != '0')     dp[i] += dp[i-1];
            int tmp = (s[i-1] - '0') * 10 + s[i] - '0';
            if(tmp >= 10 && tmp <= 26){
                if(i >= 2)  dp[i] += dp[i-2];
                else    dp[i]++;
            }
        }
        int res = dp[n-1];
        delete [] dp;
        return res;
    }
};
