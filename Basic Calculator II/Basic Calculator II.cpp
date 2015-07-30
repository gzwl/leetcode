/*
    维护一个符号栈和一个数字栈，然后扫描字符串
    1.如果是数字，看符号栈顶元素
        a.如果是*或/，那么就直接和数字栈顶元素运算
        b.否则将数字入栈
    2.如果是符号
        a.如果是*和/,就直接入栈
        b.如果是+和-，那么就先将数字栈和符号栈进行运算到不能算为止，然后将该符号入栈
    3.数字可能大于9，要读全
*/

class Solution {
public:
    int calculate(string s) {
        int n = 0;
        stack<int> digit;
        stack<char> op;
        while(n < s.size()){
            //空格跳过
            if(s[n] == ' '){
                n++;continue;
            }
            if(isdigit(s[n])) {
                int tmp = 0;
                while(n < s.size() && isdigit(s[n])){
                    tmp = tmp * 10 + s[n] - '0';
                    n++;
                }
                if(op.empty() || op.top() == '+' || op.top() == '-'){
                    digit.push(tmp);
                }
                else if(op.top() == '*') {
                    tmp = digit.top() * tmp;
                    digit.pop();
                    op.pop();
                    digit.push(tmp);
                }
                else {
                    tmp = digit.top() / tmp;
                    digit.pop();
                    op.pop();
                    digit.push(tmp);
                }
            }
            else {
                //如果是+和-，那么就先将数字栈和符号栈进行运算到不能算为止，然后将该符号入栈
                if(s[n] == '+' || s[n] == '-'){
                    while(op.size()) {
                        int digit1 = digit.top();digit.pop();
                        int digit2 = digit.top();digit.pop();
                        if(op.top() == '+')     digit.push(digit2 + digit1);
                        else    digit.push(digit2 - digit1);
                        op.pop();
                    }
                }
                //如果是*和/,就直接入栈
                op.push(s[n++]);
            }
        }
        //最后在算一遍，可能有3+5*6这种情况
        while(op.size()) {
            int digit1 = digit.top();digit.pop();
            int digit2 = digit.top();digit.pop();
            if(op.top() == '+')     digit.push(digit2 + digit1);
            else    digit.push(digit2 - digit1);
            op.pop();
        }
        return digit.top();
    }
};
