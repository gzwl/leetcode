/*
    这道题和一维情况的解法基本一致
    只不过1D时我们维护的是前缀和
    而2D时对于任意点(x,y),我们维护以(0,0)为左上角,以(x,y)为右下角的矩形中所有数的和
    那么对于每组查询(row1,col1,row2,col2)
    结果都能表示为 sum[row2][col2] - sum[row1-1][col2] - sum[row2][col1-1] + sum[row1-1][col1-1]
*/

class NumMatrix {
private:
    vector<vector<int>> &sum;
    int n,m;
public:
    NumMatrix(vector<vector<int>> &matrix):sum(matrix) {
        n = matrix.size();
        if(n)   m = matrix[0].size();
        for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++) {
            if(i)   sum[i][j] += sum[i-1][j];
            if(j)   sum[i][j] += sum[i][j-1];
            if(i && j)  sum[i][j] -= sum[i-1][j-1];
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = sum[row2][col2];
        if(row1)    res -= sum[row1-1][col2];
        if(col1)    res -= sum[row2][col1-1];
        if(row1 && col1)    res += sum[row1-1][col1-1];
        return res;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
