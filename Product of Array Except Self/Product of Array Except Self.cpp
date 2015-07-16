//不能用除法，那就从左往右扫一遍，再从右往左扫一遍，分别维护前缀积就可以了

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int base = 1;
        for(int i = 0;i < nums.size();i++){
            res.push_back(base);
            base *= nums[i];
        }
        base = 1;
        for(int i = nums.size() - 1;i >= 0;i--){
            res[i] *= base;
            base *= nums[i];
        }
        return res;
    }
};

