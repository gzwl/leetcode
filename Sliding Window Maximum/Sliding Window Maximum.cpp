/*
    维护一个单调递减的队列，队列中存的是元素的角标
    然后每个窗口的最大元素其实就是取队首的元素，注意两点：
    1、当一个元素入队列时，队列尾部中比它小的元素都排除掉，因为以后都不可能是最大的
    2、队首元素如果和当前元素的角标距离大于k时，也要排除掉
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int *que = new int[nums.size()];
        int lhs = 0,rhs = 0;
        for(int i = 0;i < k - 1;i++){
            while(rhs > lhs && nums[i] >= nums[que[rhs-1]])     rhs--;  //队列尾部比当前元素小的都排除都掉
            que[rhs++] = i;
        }
        vector<int> res;
        for(int i = k - 1;i < nums.size();i++){
            while(rhs > lhs && nums[i] >= nums[que[rhs-1]])     rhs--;  //队列尾部比当前元素小的都排除都掉
            if(rhs > lhs && i - que[lhs] + 1 > k)   lhs++;              //队首元素如果和当前元素的角标距离大于k时，也要排除掉
            que[rhs++] = i;
            res.push_back(nums[que[lhs]]);                              //当前窗口最大的就是队首元素
        }
        delete [] que;
        return res;
    }
};

