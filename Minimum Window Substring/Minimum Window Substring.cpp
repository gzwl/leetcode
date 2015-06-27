/*
    从s的左边开始扫，维护一个左端点和一个右端点
    如果当前区域有多余的字符就从左端减，有空缺就从右端加
    时间复杂度O(n)
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int cnts[300] = {0},cntt[300] = {0};
        for(int i = 0;i < t.size();i++)     cntt[t[i]]++; //统计t中每个元素的个数
        int lhs = 0,rhs = 0;
        int resl = -1,resr = s.size();  //所求字符串的左端和右端
        int sum = 0;                    //统计s中所有的t中字符的个数
        while(rhs < s.size()){
            cnts[s[rhs]]++;                //统计s中每个元素的个数
            if(cntt[s[rhs]] && cntt[s[rhs]] >= cnts[s[rhs]])   sum++;
            if(cnts[s[rhs]] > cntt[s[rhs]]){                        //如果有多余的，从s左端开始减
                while(lhs <= rhs && cnts[s[lhs]] > cntt[s[lhs]]){
                    cnts[s[lhs]]--;
                    lhs++;
                }
            }
            if(sum == t.size() && rhs - lhs < resr - resl){
                resr = rhs;
                resl = lhs;
            }
            rhs++;
        }
        string res;
        if(resl == -1)  return res;
        else    return s.substr(resl,resr - resl + 1);
    }
};
