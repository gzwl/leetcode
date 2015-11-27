/*
    首先O(n)扫一遍数组
    然后对于每个被扫到的数nums[i]，我们用平衡二叉树维护他前面的k个数
    这样我们可以二分搜索nums[i]-t
    看是否有一个数num[j]满足abs(nums[i]-nums[j]) <= t，这个复杂度为O(logk)
    于是总的time O(nlogk)
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<int> tree;

        //扫描每一个数
        for(int i = 0;i < nums.size();i++) {
            multiset<int>::iterator ite = tree.lower_bound(nums[i] - t);

            //二分查找满足条件的数
            if(ite != tree.end() && abs(nums[i] - *ite) <= t)    return true;

            tree.insert(nums[i]);

            //维护树里面的数不超过k个
            if(tree.size() > k)
                tree.erase(tree.find(nums[i-k]));
        }
        return false;
    }
};

