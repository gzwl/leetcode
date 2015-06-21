class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res;
        int lhs = -1,rhs = n;
        while(rhs - lhs > 1){
            int mid = (lhs + rhs) / 2;
            if(nums[mid] < target)  lhs = mid;
            else    rhs = mid;
        }
        if(lhs < n - 1 && nums[lhs+1] == target)  res.push_back(lhs + 1);
        else    res.push_back(-1);
        lhs = -1,rhs = n;
        while(rhs - lhs > 1){
            int mid = (lhs + rhs) / 2;
            if(nums[mid] > target)  rhs = mid;
            else    lhs = mid;
        }
        if(rhs && nums[rhs-1] == target)    res.push_back(rhs - 1);
        else    res.push_back(-1);
        return res;
    }
};
