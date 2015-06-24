class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int lhs = 0;
        while(lhs != n - 1){
            int next = lhs;
            if(lhs + nums[lhs] >= n - 1){
                return true;
            }
            for(int i = 1;i <= nums[lhs];i++){
                if(lhs + i + nums[i+lhs] >= next + nums[next]){
                    next = lhs + i;
                }
            }
            if(next == lhs)     return false;
            lhs = next;
        }
        return true;
    }
};

