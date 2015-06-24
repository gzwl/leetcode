//哈希表做法

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> mapint;
        for(int i = 0;i < nums.size();i++){
            int id = mapint[nums[i]];
            if(id == 0){
                mapint[nums[i]] = i + 1;    //这里存的是值的下标加1 因为0表示没有这个元素
            }
            else if(i - id < k)    return true;
            else{
                mapint[nums[i]] = i + 1;    //如果相同元素下标的差大于k，要用后面的下标代替前面的
            }
        }
        return false;
    }
};

//排序做法 从结果看比上面要快一些 但复杂度其实是一样的
struct state
{
    int val,id;
    bool operator<(const state &rhs)const{
        if(val != rhs.val)  return val < rhs.val;
        return id < rhs.val;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        state *a = new state[n];
        for(int i = 0;i < n;i++){
            a[i].val = nums[i];
            a[i].id = i;
        }
        sort(a,a+n);
        for(int i = 1;i < n;i++){
            if(a[i].val == a[i-1].val && a[i].id - a[i-1].id <= k){
                delete [] a;
                return true;
            }
        }
        delete [] a;
        return false;
    }
};

