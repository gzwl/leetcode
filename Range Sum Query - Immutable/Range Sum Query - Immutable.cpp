/*
    给定一个不变数组，对于多组询问，求任意区间和
    对此我们可以维护一个前缀和数组，sum[i]表示前i项的和
    那么任何区间和都能表示为两个前缀和相减
    对于每一组询问我们能在time O(1)内得到结果
*/


class NumArray {
private:
    int *sum;
    int n;
public:
    NumArray(vector<int> &nums): sum(new int[nums.size() + 1]),n(nums.size()) {
        sum[0] = 0;
        for(int i = 1;i <= n;i++)    sum[i] = sum[i-1] + nums[i-1];
    }

    ~NumArray() {
        delete [] sum;
    }

    int sumRange(int i, int j) {
        return sum[j+1] - sum[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
