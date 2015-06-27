//因为数组只有元素0,1,2 所以不需要排序 直接扫一遍统计0,1,2的个数 然后给nums赋值即可

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int cnt0 = 0,cnt1 = 0,cnt2 = 0;
        for(int i = 0;i < n;i++){
            if(nums[i] == 0)    cnt0++;
            else if(nums[i] == 1)   cnt1++;
            else    cnt2++;
        }
        for(int i = 0;i < n;i++){
            if(cnt0){
                nums[i] = 0;cnt0--;
            }
            else if(cnt1){
                nums[i] = 1;cnt1--;
            }
            else{
                nums[i] = 2;cnt2--;
            }
        }
    }
};


