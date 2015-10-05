/*
    比较简单，一开始把非0数都移到左边，剩下的自然都是0了
    time O(n) space O(1)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slot = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i])     nums[slot++] = nums[i];
        }
        for(int i = slot;i < nums.size();i++)
            nums[i] = 0;
    }
};

