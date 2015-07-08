//直接枚举每一位就可以了

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int n = strs.size();
        string s;
        if(!n)  return s;
        int len = 0x3f3f3f3f;
        for(int i = 0;i < n;i++)    if(strs[i].size() < len)  len = strs[i].size();
        for(int i = 0;i < len;i++)
        {
            char c = strs[0][i];
            bool flag = true;
            for(int j = 1;j<n;j++)
            {
                if(strs[j][i] != c)
                {
                    flag = false;break;
                }
            }
            if(flag)    s += c;
            else    break;
        }
        return s;
    }
};
