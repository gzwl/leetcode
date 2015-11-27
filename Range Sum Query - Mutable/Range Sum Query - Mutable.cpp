/*
    如果数组是不变的话，我们可以直接用前缀和来做
    但现在其实是一个改点求区间的问题
    这类问题(包括改区间求区间)，我们都可以用树状数组或线段树来做
    对于每一次查询，这两种数据结构都能在time O(logn)内得出结果
    这里我用的是写起来相对简单的树状数组(binary indexed tree)来做

    这是维基百科关于BIT的定义：https://en.wikipedia.org/w/index.php?title=Fenwick_tree&redirect=no
    因为这个数据结构讲起来篇幅比较长所以不在这里阐述
    网上关于这个的学习资料非常多，不了解的可以去看看
*/

class NumArray {
private:
    int *array;
    int *bit;
    int n;
public:
    NumArray(vector<int> &nums):bit(new int[nums.size() + 1]),array(new int[nums.size() + 1]) {
        n = nums.size();

        //树状数组初始化
        for(int i = 0;i <= n;i++) {
            bit[i] = 0;
            array[i] = 0;
        }
        for(int i = 0;i < n;i++)    update(i,nums[i]);
    }

    ~NumArray() {
        delete [] bit;
        delete [] array;
    }

    void update(int i, int val) {
        int index = i + 1;
        int change = val - array[i];
        array[i] = val;
        while(index <= n) {
            bit[index] += change;
            index += index - (index & (index - 1));
        }
    }

    int sumRange(int i, int j) {
        //这里是先求出前i项和与前j项和,再用sumj-sumi即可得出答案
        int index = i ;
        int sumi = 0,sumj = 0;
        while(index) {
            sumi += bit[index];
            index &= index - 1;
        }
        index = j + 1;
        while(index) {
            sumj += bit[index];
            index &= index - 1;
        }
        return sumj - sumi;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
