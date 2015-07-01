/*
    res表示解
    cnt表示它的净个数，如果有超过n/2的数，那么它的净个数一定是大于0的
    时间复杂度O(n)
    空间复杂度O(1)
*/



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0],cnt = 1;
        for(int i = 1;i < n;i++){
            if(nums[i] == res)  cnt++;      //可能的解与当前数相同就加
            else if(cnt == 0){              //没有解就把当前数作为可能的解
                res = nums[i];
                cnt++;
            }
            else    cnt--;                  //可能的解与当前数不同就减
        }
        return res;
    }
};
