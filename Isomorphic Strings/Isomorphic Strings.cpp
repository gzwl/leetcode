class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int val1[300] = {0};
        int val2[300] = {0};
        for(int i = 0;i < s.size();i++){
            if(val1[s[i]] && val1[s[i]] != t[i]){
                return false;
            }
            else if(val1[s[i]] == 0 && val2[t[i]]){
                return false;
            }
            val1[s[i]] = t[i];
            val2[t[i]] = s[i];
        }
        return true;
    }
};

