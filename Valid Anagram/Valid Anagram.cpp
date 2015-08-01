//用数组记录每个字母出现的次数，如果都是0就true，否则false

class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[26];
        memset(cnt,0,sizeof(cnt));
        for(int i = 0;i < s.size();i++)     cnt[s[i]-'a']++;
        for(int i = 0;i < t.size();i++)     cnt[t[i]-'a']--;
        for(int i = 0;i < 26;i++)   if(cnt[i])      return false;
        return true;
    }
};

