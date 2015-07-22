/*
    枚举0~numRows-1行，然后分别把每一行的元素加进去
    注意第0行和第numRows-1行因为没有对角线元素，所以相邻元素隔了(2*numRows-2)
    但是第1~第numRows-2行中存在对角线元素，还要另行考虑
    题目比较基础，推下公式就可以了
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)    return s;
        string res;
        for(int i = 0;i < numRows;i++){
            for(int j = i;j < s.size();j += 2*numRows - 2){
                res += s[j];
                //要加上对角元素
                if(i != 0 && i != numRows - 1 && j+2*(numRows-1-i) < s.size()){
                    res += s[j+2*(numRows-1-i)];
                }
            }
        }
        return res;
    }
};
