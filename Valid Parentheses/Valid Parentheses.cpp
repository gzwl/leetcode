class Solution {
public:
    bool isValid(string s) {
        int n = s.size();                                   //为了节省空间，直接用s来表示栈
        int top = 0;
        for(int i = 0;i < n;i++){                           //O(n)扫一遍
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')   //如果是这些元素就直接入栈
                s[top++] = s[i];
            else{
                if(top == 0)    return false;               //否则看能不能和栈顶元素删去，如果不能就不可以
                if(s[i] == ')' && s[top - 1] != '(')    return false;
                if(s[i] == ']' && s[top - 1] != '[')    return false;
                if(s[i] == '}' && s[top - 1] != '{')    return false;
                top--;
            }
        }
        if(top)     return false;       //如果最后栈内还有元素也不可以
        return true;
    }
};

