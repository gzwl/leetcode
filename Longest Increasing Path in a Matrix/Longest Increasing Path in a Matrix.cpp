/*
    这道题其实就是求有向无环图的最长路径
    直接深搜就可以做
    time O(nm)  space O(nm)
*/

class Solution {
private:
    //搜索的四个方向
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    int n;
    int m;

    //以某个点(i,j)为起点的最长路径为longestPath[i][j]
    int **longestPath;

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        //创建数组并初始化为0
        n = matrix.size();
        if(n == 0)  return 0;
        m = matrix[0].size();
        longestPath = new int*[n];
        for(int i = 0;i < n;i++) {
            longestPath[i] = new int[m];
            for(int j = 0; j < m;j++)
                longestPath[i][j] = 0;
        }

        //搜索每一个点
        int result = 0;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                result = max(result, dfs(i,j,matrix));
            }
        }

        //回收
        for(int i = 0;i < n;i++)    delete [] longestPath[i];
        delete [] longestPath;
        return result;
    }

    int dfs(int row, int col, vector<vector<int>>& matrix) {
        //搜索过就直接返回
        if(longestPath[row][col] != 0)  return longestPath[row][col];

        //从该点的四个方向搜索最长路径
        for(int i = 0;i < 4;i++) {
            int nextRow = row + dx[i];
            int nextCol = col + dy[i];
            //判断合法性
            if(nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m && matrix[row][col] > matrix[nextRow][nextCol])
                longestPath[row][col] = max(longestPath[row][col], dfs(nextRow,nextCol,matrix));
        }
        return ++longestPath[row][col];
    }

};

