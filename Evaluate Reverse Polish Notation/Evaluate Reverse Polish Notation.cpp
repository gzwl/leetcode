/*
    求一个逆波兰式的结果，直接用栈模拟就可以了
    详见代码
*/

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        for(int i = 0;i < tokens.size();i++) {
            int m = tokens[i].size();

            //如果是符号就运算后将结果入栈
            if(m == 1 && !isdigit(tokens[i][0])) {
                 int op2 = s.top();s.pop();
                 int op1 = s.top();s.pop();
                 switch(tokens[i][0]) {
                    case '+' : s.push(op1 + op2);break;
                    case '-' : s.push(op1 - op2);break;
                    case '*' : s.push(op1 * op2);break;
                    case '/' : s.push(op1 / op2);break;
                 }
            }

            //如果是数就直接入栈
            else {
                int res = 0;
                if(tokens[i][0] != '-') {
                    for(int j = 0;j < m;j++)    res = res * 10 + tokens[i][j] - '0';
                }
                else {
                    for(int j = 1;j < m;j++)    res = res * 10 + tokens[i][j] - '0';
                    res *= -1;
                }
                s.push(res);
            }
        }
        return s.top();
    }
};
