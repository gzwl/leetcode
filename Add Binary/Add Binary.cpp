class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length() < b.length())     swap(a,b);
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int add = 0;
        for(int i = 0;i < a.size();i++){
            if(i < b.size()){
                if(a[i] == '0' && b[i] == '0'){
                    a[i] = '0' + add;
                    add = 0;
                }
                else if(a[i] == '1' && b[i] == '1'){
                    a[i] = add ? '1' : '0';
                    add = 1;
                }
                else{
                    if(add)     a[i] = '0';
                    else        a[i] = '1';
                }
            }
            else{
                if(!add)    break;
                if(a[i] == '0')     {a[i] = '1';add = 0;}
                else a[i] = '0';
            }
        }
        if(add)  a += '1';
        reverse(a.begin(),a.end());
        return a;
    }
};

