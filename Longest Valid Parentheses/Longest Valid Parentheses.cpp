class Solution {
public:
    int longestValidParentheses(string s) {
        int start = -1,res = 0,top = 0;
        int n = s.size();
        int *stack = new int[n];
        for(int i = 0;i < n;i++){
            if(s[i] == '(')     stack[top++] = i;
            else{
                if(top == 0){
                    start = i;continue;
                }
                else if(top == 1){
                    res = max(i - start,res);
                    top--;
                }
                else{
                    top--;
                    res = max(i - stack[top-1],res);
                }
            }
        }
        delete [] stack;
        return res;
    }
};
