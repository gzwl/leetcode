/*
    将字符串翻转，问题比较简单，time O(n)
*/

class Solution {
public:
    string reverseString(string s) {
        for(int i = 0;i < s.length() / 2;i++) {
            swap(s[i], s[s.length()-i-1]);
        }
        return s;
    }
};

