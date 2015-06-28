/*
    枚举每一行的每一列，如果与前面放的冲突，就回溯
*/


class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        int *col = new int[n];          //存放每一行放皇后的列数
        dfs(res,col,0,n);
        delete [] col;
        return res;
    }
    void dfs(int &res,int *col,int cur,int n)
    {
        if(n == cur){
            res++;
        }
        else{
            for(int i = 0;i < n;i++){           //枚举当前行的列
                bool flag = true;
                for(int j = 0;j < cur;j++){         //枚举前面行放皇后的列
                    if(col[j] == i || abs(cur - j) == abs(col[j] - i)){     //在同一列或在同一对角线就跳过
                        flag = false;break;
                    }
                }
                if(flag){
                    col[cur] = i;
                    dfs(res,col,cur + 1,n);
                }
            }
        }
    }
};

