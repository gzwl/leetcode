class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        int i = 0,j = 0;
        while(1){
            bool stars = false,starp = false;
            while(i < n && s[i] == '*'){
                i++;
                stars = true;
            }
            while(j < m && p[j] == '*'){
                j++;
                starp = true;
            }
            if(i == n && j == m)    return true;
            else if(i == n && stars)    return true;
            else if(j == m && starp)    return true;
            else    return false;
            if(s[i] == s[j])    continue;
            else if(s[i] == )
        }
    }
};

