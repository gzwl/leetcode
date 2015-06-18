class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(),num.end());
        vector<vector<int> > res;
        int n = num.size();
        if(n < 3)   return res;
        for(int i = 0; i < n; i++){
            if(i && num[i] == num[i-1])     continue;
            int lhs = i+1,rhs = n-1;
            while(rhs > lhs){
                 if(rhs != n-1 && num[rhs] == num[rhs+1])   rhs--;
                 else if(lhs != i+1 && num[lhs] == num[lhs-1])      lhs++;
                 else if(num[i] + num[lhs] + num[rhs] > 0)   rhs--;
                 else if(num[i] + num[lhs] + num[rhs] < 0)   lhs++;
                 else{
                    res.push_back((vector<int>){num[i],num[lhs],num[rhs]});
                    lhs++;
                    rhs--;
                 }
            }
        }
        return res;
    }
};
