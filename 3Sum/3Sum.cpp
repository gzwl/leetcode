/*
    假设三个数  a <= b <= c 
    为了求a+b+c == 0  于是我们先排序然后O(n)枚举a
    然后对于每个a我们再O(n)枚举a右边的数
    最后总的时间复杂度O(n^2)
*/

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(),num.end());
        vector<vector<int> > res;
        int n = num.size();
        if(n < 3)   return res;
        for(int i = 0; i < n; i++){                             //枚举a
            if(i && num[i] == num[i-1])     continue;           //排除重复的解
            int lhs = i+1,rhs = n-1;                            //b和c的下标
            while(rhs > lhs){                                   //O(n)枚举b和c
                 if(rhs != n-1 && num[rhs] == num[rhs+1])   rhs--;              //排除重复的解
                 else if(lhs != i+1 && num[lhs] == num[lhs-1])      lhs++;      //排除重复的解
                 else if(num[i] + num[lhs] + num[rhs] > 0)   rhs--;             
                 else if(num[i] + num[lhs] + num[rhs] < 0)   lhs++;
                 else{
                    res.push_back((vector<int>){num[i],num[lhs],num[rhs]});     //找到解
                    lhs++;
                    rhs--;
                 }
            }
        }
        return res;
    }
};

