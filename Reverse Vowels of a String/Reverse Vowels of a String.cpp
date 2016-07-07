/*
    比较简单的问题，从两边开始一起扫，然后发现是元音字母就交换即可。
    time O(n) space O(1)
*/

class Solution {
private:
    char vowels[5] = {'a','e','i','o','u'};
public:
    string reverseVowels(string s) {
        int lhs = 0, rhs = s.length() - 1;
        while(1) {
            while(lhs < s.length() && !isVowel(s[lhs]))     lhs++;
            while(rhs >= 0 && !isVowel(s[rhs]))     rhs--;
            if(lhs < rhs)   swap(s[lhs++],s[rhs--]);
            else    return s;
        }
    }

    bool isVowel(char c) {
        for(int i = 0;i < 5;i++)
            if(vowels[i] == tolower(c))  return true;
        return false;
    }
};

