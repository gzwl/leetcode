/*
    其实就是找第一个>=target的数，基本的二分
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lhs = -1,rhs = nums.size();
        while(rhs - lhs > 1){
            int mid = (rhs + lhs)/2;
            if(nums[mid] >= target)     rhs = mid;
            else    lhs = mid;
        }
        return rhs;
    }
};


