/*
    time complexity O(nm)
    space complexity O(1)
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = n ? matrix[0].size() : 0;
        bool row = false,col = false;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(matrix[i][j] == 0){             //if matrix[i][j] is 0
                    if(i == 0)  col = true;        //then make matrix[i][0]=0 and matrix[0][j]=0
                    if(j == 0)  row = true;        //but special judge if matrix[i][j] on the edge
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1;i < n;i++){
            if(matrix[i][0] == 0){
                for(int j = 1;j < m;j++)
                    matrix[i][j] = 0;
            }
        }
        for(int i = 1;i < m;i++){
            if(matrix[0][i] == 0){
                for(int j = 1;j < n;j++)
                    matrix[j][i] = 0;
            }
        }
        if(row)    for(int i = 1;i < n;i++)    matrix[i][0] = 0;
        if(col)    for(int i = 1;i < m;i++)    matrix[0][i] = 0;
    }
};

