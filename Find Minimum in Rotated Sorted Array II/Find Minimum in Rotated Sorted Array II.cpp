/*
    二分法，假设当期区间为[lhs,rhs),如果nums[lhs] < nums[rhs-1],说明是单调的,就返回nums[lhs]
    否则说明不是单调的，就继续二分搜索[lhs，rhs)
    由于多了相等的情况，每次搜索不一定能减去一半的区间
    所以平均复杂度是O(logn)的，最坏复杂度是O(n)的

*/
class Solution {
public:
    int findMin(vector<int> &nums) {
        return solve(nums,0,nums.size());
    }
    int solve(vector<int> &nums,int lhs,int rhs)
    {
        if(rhs - lhs == 1)    return nums[lhs];
        else{
            if(nums[lhs] < nums[rhs-1])   return nums[lhs];
            else{
                return min(solve(nums,lhs,(lhs + rhs) / 2),solve(nums,(lhs + rhs) / 2,rhs));
            }
        }
    }
};


