class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0],cnt = 1;
        for(int i = 1;i < n;i++){
            if(nums[i] == res)  cnt++;
            else if(cnt == 0){
                res = nums[i];
                cnt++;
            }
            else    cnt--;
        }
        return res;
    }
};
