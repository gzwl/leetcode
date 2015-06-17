class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        int n = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[n-1] != nums[i]){
                nums[n++] = nums[i];
            }
        }
        return n;
    }
};
