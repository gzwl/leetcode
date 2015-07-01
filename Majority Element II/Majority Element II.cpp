/*
    用res1和res2维护两个可能的解
    cnt1和cnt2表示它们的净个数，如果有超过n/3的数，那么它的净个数一定是大于0的
    时间复杂度O(n)
    空间复杂度O(1)
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int res1,res2;                      //出现次数大于n/3，最多只可能有两个解res1,res2
        int cnt1 = 0,cnt2 = 0;              //净个数
        for(int i = 0;i < nums.size();i++){
            if(cnt1 && nums[i] == res1)     cnt1++;         //当前数和res1相同
            else if(cnt2 && nums[i] == res2)    cnt2++;     //当前数和res2相同
            else if(cnt1 == 0){                             //res1没存数
                res1 = nums[i];cnt1++;
            }
            else if(cnt2 == 0){                             //res2没存数
                res2 = nums[i];cnt2++;
            }
            else{                                           //当前数和res1,res2均不同
                cnt1--;cnt2--;
            }
        }
        //上面得到的是可能的两个解res1,res2,现在验证这两个解
        int sum1 = 0,sum2 = 0;                      //sum1,sum2分别为res1和res2在数组中出现的次数
        for(int i = 0;i < nums.size();i++){
            if(cnt1 && nums[i] == res1)     sum1++;
            if(cnt2 && nums[i] == res2)     sum2++;
        }
        vector<int> res;
        if(sum1 > nums.size() / 3)  res.push_back(res1);
        if(sum2 > nums.size() / 3)  res.push_back(res2);
        return res;
    }
};


