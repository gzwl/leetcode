/*
    因为没有整个区间的单调性，所以不能像I那样直接二分
    我们可以从矩阵右上角开始, 比较target 和 matrix[x][y]的值
    如果小于target, 则该行不可能有此数,  所以x++
    如果大于target, 则该列不可能有此数, 所以y--
    遇到边界则表明该矩阵不含target

    O(n+m) time

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0)  return false;
        int m = matrix[0].size();
        int x = 0,y = m - 1;
        while(x < n && y >= 0){
            if(matrix[x][y] > target)   --y;
            else if(matrix[x][y] < target)      ++x;
            else       return true;
        }
        return false;
    }
};

