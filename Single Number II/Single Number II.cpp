class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bit[32] = {0};
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < 32 ; j++){
                if((1<<j) & nums[i]){
                    bit[j]++;
                }
            }
        }
        int res = 0;
        for(int i = 0; i < 32; i++){
            if(bit[i] % 3){
                res |= (1<<i);
            }
        }
        return res;
    }
};
