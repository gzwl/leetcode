/*
    把位置相同和位置不同但数字对的分别找出来
    然后转换成字符串就可以了，详见代码
*/

class Solution {
public:
    string getHint(string secret, string guess) {
        int secretCnt[10] = {0},guessCnt[10] = {0};
        int cntA = 0,cntB = 0;

        //找出A
        for(int i = 0;i < secret.size();i++) {
            if(secret[i] == guess[i])   cntA++;
            else {
                secretCnt[secret[i] - '0']++;
                guessCnt[guess[i] - '0']++;
            }
        }

        //找出B
        for(int i = 0;i < 10;i++)   cntB += min(secretCnt[i],guessCnt[i]);
        return toString(cntA) + 'A' + toString(cntB) + 'B';
    }

private:
    string toString(int num) {
        if(num == 0)    return "0";
        string res;
        while(num) {
            res += '0' + num % 10;
            num /= 10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

