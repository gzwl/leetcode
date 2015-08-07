/*
    普通地模拟手算就可以了
    不过要注意进位和删除前导0
*/


class Solution {
public:
    string multiply(string num1, string num2) {
	    string res(num1.size() + num2.size(), '0');
	    for (int i = num1.size() - 1, d = res.size()-1; i >= 0; i--, d--){
		    int carry = 0, k = d;
		    for (int j = num2.size()-1; j >= 0; j--, k--){
			    int a = num1[i] - '0';
			    int b = num2[j] - '0';
			    a = a * b + carry + (res[k] - '0');
			    carry = a/10;
			    res[k] = a%10 + '0';
		    }
		    while (carry){
			    int sum = carry + (res[k] - '0');
			    carry = sum / 10;
			    res[k--] = sum % 10 + '0';
		    }
	    }
	    string::iterator ite = res.begin();
	    while(*ite == '0' && ite != --res.end())    ite++;
	    res.erase(res.begin(),ite);
	    return res;
    }

};


