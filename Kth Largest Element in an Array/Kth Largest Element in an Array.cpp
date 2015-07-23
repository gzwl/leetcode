/*
    求数列中第k大的数
    那么扫描一遍数组，同时维护一个容量为k的小顶堆就可以了
    最后答案就是小顶堆的头元素
    O(nlogk) time

*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int> > q;
        for(int i = 0;i < nums.size();i++){
            if(q.size() < k)    q.push(nums[i]);
            else if(q.top() < nums[i]){
                q.pop();
                q.push(nums[i]);
            }
        }
        return q.top();
    }
};

