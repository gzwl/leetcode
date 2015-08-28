/*
    这道题和First Missing Positive同一个做法
    我们把0~n-1分别调整到nums[0]~nums[n-1]的位置上
    然后看看哪位不对应就是哪位，如果都对应那就是n了
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < n;i++){
            if(nums[i] < n){
                if(nums[i] == i)    continue;
                if(nums[nums[i]] != nums[i]){
                    swap(nums[nums[i]],nums[i]);
                    i--;
                }
            }
        }
        for(int i = 0;i < n;i++){
            if(nums[i] != i)    return i;
        }
        return n;
    }
};

