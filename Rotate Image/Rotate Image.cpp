/*
    将一个矩阵顺时针旋转90°
    推出每个点旋转后的位置
    然后就地旋转就可以了
*/

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int x = 0;
        for(int len = n;len > 0;len -= 2){
            if(len == 1)    break;
            for(int y = x;y < x + len - 1;y++)
            {
                int tmp = matrix[x][y];
                matrix[x][y] = matrix[2*x+len-1-y][x];
                matrix[2*x+len-1-y][x] = matrix[x+len-1][2*x+len-1-y];
                matrix[x+len-1][2*x+len-1-y] = matrix[y][x+len-1];
                matrix[y][x+len-1] = tmp;
            }
            x++;
        }
    }
};

