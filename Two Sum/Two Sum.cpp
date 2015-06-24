/*
    排序后从左右端点开始扫描
    复杂度O(nlogn)
*/

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        int n = numbers.size();
        int *a = new int[n];
        for(int i = 0;i < n;i++)    a[i] = numbers[i];
        sort(numbers.begin(),numbers.end());
        int lhs = 0,rhs = n-1;
        while(rhs > lhs){
            if(numbers[lhs] + numbers[rhs] > target)    rhs--;
            else if(numbers[lhs] + numbers[rhs] < target)   lhs++;
            else{
                int id1,id2;
                for(int i = 0;i < n;i++){
                    if(a[i] == numbers[lhs]){
                        id1 = i + 1;
                        break;
                    }
                }
                for(int i = n - 1;i >= 0;i--){
                    if(a[i] == numbers[rhs]){
                        id2 = i + 1;
                        break;
                    }
                }
                res.push_back(min(id1,id2));
                res.push_back(max(id1,id2));
                return res;
            }
        }
    }
};
