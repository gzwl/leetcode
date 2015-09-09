/*
    可以分为5步
    1.去除string的前导0
    2.翻转string
    3.再去除string的前导0
    4.去除每个单词间多于一个的0
    5.将每个单词翻转
    然后慢慢搞就可以了...
*/

class Solution {
public:
    void reverseWords(string &s) {
        int len = cut_head_zero(s,s.size());
        reverse(s.begin(),s.begin() + len);
        len = cut_head_zero(s,len);
        len = cut_inside_zero(s,len);
        for(int i = 0;i < len;i++){
            int j;
            for(j = i;j < len;j++)  if(s[j] == ' ')     break;
            reverse(s.begin() + i,s.begin() + j);
            i = j;
        }
        s.erase(len);
    }

    int cut_head_zero(string &s,int old_len){
        int len = 0;
        int i = 0;
        while(i < old_len && s[i] == ' ')   ++i;
        while(i < old_len)  s[len++] = s[i++];
        return len;
    }

    int cut_inside_zero(string &s,int old_len){
        int len = 0;
        bool in_word = false;
        for(int i = 0;i < old_len;i++){
            if(s[i] != ' '){
                in_word = true;
                s[len++] = s[i];
            }
            else if(in_word){
                in_word = false;
                s[len++] = ' ';
            }
        }
        return len;
    }
};

