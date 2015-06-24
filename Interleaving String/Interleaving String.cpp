class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())    return 0;
        int **dp = new int*[s1.size()+1];
        for(int i = 0;i <= s1.size();i++){
            dp[i] = new int[s2.size()+1];
            for(int j = 0;j <= s2.size();j++){
                dp[i][j] = 0;  
            }
        }               //dp[i][j]表示s1的前i个字符和s2的前j个字符能否构成s3的前i+j个字符，然后状态转移就可以了
        dp[0][0] = 1;
        for(int len = 1;len <= s3.size();len++){
            for(int len1 = max(0,(int)(len - s2.size()));len1 <= min(len,(int)s1.size());len1++){
                int len2 = len - len1;
                if(len1 && dp[len1-1][len2] && s1[len1-1] == s3[len-1]){
                    dp[len1][len2] = 1;
                }
                if(len2 && dp[len1][len2-1] && s2[len2-1] == s3[len-1]){
                    dp[len1][len2] = 1;
                }
            }
        }
        bool res = dp[s1.size()][s2.size()] ? 1 : 0;
        for(int i = 0;i <= s1.size();i++)   delete [] dp[i];
        delete [] dp;
        return res;
    }
};

