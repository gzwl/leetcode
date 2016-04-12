/*
    因为要让字典序最小，所以我们要让小的字母尽可能的在前面，除非前面有一个字母只出现了一次
    time O(n)
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int count[26] = {0};
        bool exist[26] = {0};

        //统计每个字母出现次数
        for(int i = 0;i < s.length();i++)   count[s[i]-'a']++;

        //维护到当前位置为止的最小字符串
        deque<int> letters;


        for(int i = 0;i < s.length();i++) {
            //如果当前字母已经在最小字符串中，跳过
            if(exist[s[i]-'a']) {
                count[s[i]-'a']--;
                continue;
            }
            //对于当前字母，我们把它插入最小字符串尾部，然后删掉前面大于等于它且不只出现一次的字母
            while(letters.size() && count[letters.back()-'a'] > 1 && s[i] <= letters.back()) {
                count[letters.back()-'a']--;
                exist[letters.back()-'a'] = false;
                letters.pop_back();
            }
            letters.push_back(s[i]);
            exist[s[i]-'a'] = true;
        }
        return string(letters.begin(),letters.end());
    }
};
