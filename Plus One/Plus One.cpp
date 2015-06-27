/*
    解法很直接了，就是模拟手算
    不过要注意进位
*/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size();
        reverse(digits.begin(),digits.end());
        int in = 1;     
        for(int i = 0; i < n && in; i++){
            digits[i] += in;
            in = 0;
            if(digits[i] > 9 ){     //进位
                digits[i] = 0;
                in = 1;
            }
        }
        if(in)  digits.push_back(1);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};

