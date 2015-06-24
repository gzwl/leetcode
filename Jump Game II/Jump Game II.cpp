class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int lhs = 0;
        int res = 0;
        while(lhs != n - 1){
            int next = lhs;
            if(lhs + nums[lhs] >= n - 1){
                return res + 1;
            }
            for(int i = 1;i <= nums[lhs];i++){
                if(lhs + i + nums[i+lhs] >= next + nums[next]){
                    next = lhs + i;
                }
            }
            lhs = next;
            res++;
        }
        return res;
    }
};

