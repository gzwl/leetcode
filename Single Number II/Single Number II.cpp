/*
    一个int有32位，所以我们扫一遍数组并记录每一位出现的次数
    因为除了一个数以外其他数都出现3次
    所以如果某一位是3的倍数，就说明答案中该位为0，否则该位为1
*/


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
