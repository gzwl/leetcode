/*
    首先找到每一个谷底，即 ratings[i] <= ratings[i-1] && ratings[i] <= ratings[i+1]的点i
    然后不断地从点i的左边和右边分别往上爬
    即若ratings[i-1] >= ratings[i] , 则cost[i-1] = max(cost[i-1],cost[i]+1)
    和ratings[i+1] >= ratings[i] , 则cost[i+1] = max(cost[i+1],cost[i]+1)
    其中cost[i]表示第i个小朋友拿到的糖
*/



class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n <= 1)  return n;
        int *cost = new int[n];
        for(int i = 0;i < n;i++)    cost[i] = 1;//每个小朋友拿的糖，初始化为1
        for(int i = 0;i < n;i++){
            //找到谷底
            if((i == 0 && ratings[i] <= ratings[i+1]) ||
               (i == n - 1 && ratings[i] <= ratings[i-1] ) ||
               (i > 0 && i < n - 1 && ratings[i] <= ratings[i+1] && ratings[i] <= ratings[i-1])){
                    int lhs = i - 1,rhs = i + 1;
                    //往左爬
                    while(lhs >= 0 && ratings[lhs] > ratings[lhs+1] && cost[lhs] < cost[lhs+1] + 1){
                        cost[lhs] = cost[lhs+1] + 1;
                        lhs--;
                    }
                    //往右爬
                    while(rhs < n && ratings[rhs] > ratings[rhs-1] && cost[rhs] < cost[rhs-1] + 1){
                        cost[rhs] = cost[rhs-1] + 1;
                        rhs++;
                    }
            }
        }
        int res = 0;
        for(int i = 0;i < n;i++)    res += cost[i];
        delete [] cost;
        return res;
    }
    
};

