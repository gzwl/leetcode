/*
    这个问题的关键在于如何快速的知道两个字符串是否有相同的字符
    由于字母最多只有26个，所以我们可以用一个int类型数的每一个二进制位来表示每一个字母
    例如"ad"表示为(1001)2，"bbc"表示为(110)2
    这样判断两个字符串是否有相同的字母就看代表它们的数相&是否为0即可
    time O(n^2 + length)
*/

class Solution {
public:
    int maxProduct(vector<string>& words) {

        //预处理出每个字符串的哈希数
        vector<int> bit(words.size(), 0);
        for(int i = 0;i < words.size();i++) {
            for(int j = 0;j < words[i].length();j++) {
                bit[i] |= (1 << (words[i][j] - 'a'));
            }
        }

        //枚举求解
        int result = 0;
        for(int i = 0;i < words.size();i++) {
            for(int j = i + 1;j < words.size();j++) {
                if((bit[i] & bit[j]) == 0 && words[i].length() * words[j].length() > result)
                    result = words[i].length() * words[j].length();
            }
        }
        return result;
    }
};

