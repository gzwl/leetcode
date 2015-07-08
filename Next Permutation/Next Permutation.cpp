/*
    求下一个排列
    大致思路是首先找到最长的逆序结尾，比如说42531，最长的逆序结尾就是531
    然后找最长逆序结尾前面的那个数，这里是2，那下一个排列一定是在逆序结尾中比2要大的最小的数，这里是3
    然后将2和3交换位置，得到43521，在把它从小排序，就得到43125，这个就是答案了
    还有要注意如果最长逆序结尾就是本身，比如54321，那么下一个排列就是12345
*/

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int n = num.size();
        bool flag = false;
        for(int i = n - 2;i >= 0;i--)     if(num[i] < num[i+1] && !flag){
            int id = i + 1;
            for(int j = id + 1;j < n;j++){
                if(num[j] > num[i] && num[j] <num[id])  id = j;
            }
            swap(num[i],num[id]);
            sort(num.begin() + i + 1,num.end());
            flag = true;
        }
        if(!flag)   sort(num.begin(),num.end());
    }
};
