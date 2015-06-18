class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int res = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        for(int i = 0; i < n && res != target; i++){
            if(i && nums[i] == nums[i-1])     continue;
            int lhs = i+1,rhs = n-1;
            while(rhs > lhs){
                 int tmp = nums[i] + nums[lhs] + nums[rhs];
                 if(abs(tmp - target) < abs(res - target)){
                     res = tmp;
                 }
                 if(tmp > target)   rhs--;
                 else if(tmp < target)   lhs++;
                 else   break;
            }
        }
        return res;
    }
};
