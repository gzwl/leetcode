
/*
    这道题的解法应该和3sum是一致的，使用两点夹逼的方法，只不过多了一维要轮询
    time O(n^3)  space O(1)
    另外此题的常数优化比较重要，这个受测试数据因素的影响比较大

    还有就是这题用哈希的方法复杂度应该也是time O(n^3)，因为一个值可能会对应多个pair，并且要考虑去重的问题
    而且哈希的话是space O(n^2)的，查询过程中常数比较大，因此TLE的可能性比较大
*/

//剪枝前，160ms
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > res;
        int n = nums.size();
        if(n < 4)   return res;
        for(int i = 0; i < n; i++){
            if(i && nums[i] == nums[i-1])     continue;
            for(int j = i + 1;j < n;j++) {
                if(j > i + 1 && nums[j] == nums[j-1])     continue;
                int lhs = j + 1,rhs = n - 1;
                while(rhs > lhs){
                    if(rhs != n-1 && nums[rhs] == nums[rhs+1])   rhs--;
                    else if(lhs != j+1 && nums[lhs] == nums[lhs-1])      lhs++;
                    else if(nums[i] + nums[lhs] + nums[rhs] + nums[j] > target)   rhs--;
                    else if(nums[i] + nums[lhs] + nums[rhs] + nums[j] < target)   lhs++;
                    else{
                        res.push_back((vector<int>){nums[i],nums[j],nums[lhs],nums[rhs]});
                        lhs++;
                        rhs--;
                    }
                }
            }
        }
        return res;
    }
};

//剪枝后，24ms
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > res;
        int n = nums.size();
        if(n < 4)   return res;
        for(int i = 0; i < n - 3; i++){
            if(i && nums[i] == nums[i-1])     continue;
            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target)    break;
            if(nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target)    continue;
            for(int j = i + 1;j < n - 2;j++) {
                if(j > i + 1 && nums[j] == nums[j-1])     continue;
                if(nums[i] + nums[j] + nums[n-1] + nums[n-2] < target)  continue;
                if(nums[i] + nums[j] + nums[i+1] + nums[i+2] > target) {
                    break;
                }
                int lhs = j + 1,rhs = n - 1;
                while(rhs > lhs){
                    if(rhs != n-1 && nums[rhs] == nums[rhs+1])   rhs--;
                    else if(lhs != j+1 && nums[lhs] == nums[lhs-1])      lhs++;
                    else if(nums[i] + nums[lhs] + nums[rhs] + nums[j] > target)   rhs--;
                    else if(nums[i] + nums[lhs] + nums[rhs] + nums[j] < target)   lhs++;
                    else{
                        res.push_back((vector<int>){nums[i],nums[j],nums[lhs],nums[rhs]});
                        lhs++;
                        rhs--;
                    }
                }
            }
        }
        return res;
    }
};

