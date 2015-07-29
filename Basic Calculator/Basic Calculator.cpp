/*
    维护一个数字栈和一个符号栈，然后扫一遍字符串
    1.如果+,-,(就直接入符号栈
    2.如果是数字，看符号栈
        a.如果符号栈顶是+、-,把该元素和数字栈顶元素进行相应运算并存入数字栈顶
        b.否则直接将该数字入栈
    3.如果是),直接把符号栈栈顶元素给弹出，因为栈顶元素必然是(，然后将符号栈和数字栈进行运算，直到不能运算为止
    4.注意数字可能大于9

*/
class Solution {
public:
    int calculate(string s) {
        stack<int> digit;
        stack<char> op;
        int n = 0;
        while(n < s.size()){
            //空格跳过
            if(isspace(s[n])){
                n++;
                continue;
            }
            if(isdigit(s[n])){
                //读数字
                int tmp = 0;
                while(n < s.size() && isdigit(s[n])){
                    tmp = 10 * tmp + s[n] - '0';
                    n++;
                }
                if(op.empty() || op.top() == '(')  digit.push(tmp);
                else if(op.top() == '+'){
                    tmp = digit.top() + tmp;
                    digit.pop();
                    op.pop();
                    digit.push(tmp);
                }
                else {
                    tmp = digit.top() - tmp;
                    digit.pop();
                    op.pop();
                    digit.push(tmp);
                }
            }
            else{
                //如果是),直接把符号栈栈顶元素给弹出，因为栈顶元素必然是(，然后将符号栈和数字栈进行运算，直到不能运算为止
                if(s[n] == ')'){
                    op.pop();
                    while(op.size() && op.top() != '('){
                        int digit1 = digit.top();digit.pop();
                        int digit2 = digit.top();digit.pop();
                        if(op.top() == '+')     digit.push(digit2 + digit1);
                        else    digit.push(digit2 - digit1);
                        op.pop();
                    }
                }
                //如果+,-,(就直接入符号栈
                else    op.push(s[n]);
                n++;
            }
        }
        return digit.top();
    }
};
