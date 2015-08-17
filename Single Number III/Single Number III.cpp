/*
    1.假设解是res1和res2,我们先把所有数做XOR,这样得到res1^res2
    2.因为 res1 != res2,所以结果一定有一位bit是1
    3.于是我们可以把数分成两组,一组bit位上为1,另一组bit位上为0
    4.两组分别做XOR,就可以得到两个解res1和res2了
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int bit = 0;
        for(int i = 0;i < nums.size();i++)     bit ^= nums[i];
        bit -= bit & (bit - 1);
        int res1 = 0,res2 = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] & bit)   res1 ^= nums[i];
            else    res2 ^= nums[i];
        }
        return vector<int>{res1,res2};
    }
};
