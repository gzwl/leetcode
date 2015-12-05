/*
    在一个数组里面找一个index，使得nums[index-1] < nums[index] > nums[index+1]
    形象点说就是从许多个山峰里面找到一个山峰即可
    那么我们可以二分查找不断夹紧，对于每一次二分查找我们有左端点lhs，右端点rhs，中点mid
    1.如果mid是上坡，则令lhs = mid
    2.如果mid是下坡，则令rhs = mid
    3.否则mid是山峰，即为所求
    time O(logn)
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lhs = 0,rhs = nums.size();
        while(rhs > lhs) {
            int mid = lhs + (rhs - lhs) / 2;
            bool left = 0,right = 0;

            //比左边大
            if(mid == 0 || nums[mid] > nums[mid-1])   left = 1;

            //比右边大
            if(mid == nums.size() - 1 || nums[mid] > nums[mid+1])   right = 1;

            //山峰
            if(left && right)   return mid;

            //上坡
            else if(left && !right)     lhs = mid + 1;

            //下坡
            else    rhs = mid;
        }
    }
};

