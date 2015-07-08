//直接枚举即可

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int vis[9] = {0};
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){                   //每一行
                if(!isdigit(board[i][j]))   continue;
                if(vis[board[i][j]-'1'])      return false;
                vis[board[i][j]-'1'] = 1;
            }
            memset(vis,0,sizeof(vis));
        }
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){                   //每一列
                if(!isdigit(board[j][i]))   continue;
                if(vis[board[j][i]-'1'])      return false;
                vis[board[j][i]-'1'] = 1;
            }
            memset(vis,0,sizeof(vis));
        }
        memset(vis,0,sizeof(vis));
        for(int i = 0;i < 9;i += 3){                    //每一个正方形
            for(int j = 0;j < 9;j += 3){
                for(int r = 0;r < 3;r++){
                    for(int c = 0;c < 3;c++){
                        if(!isdigit(board[i+r][j+c]))   continue;
                        if(vis[board[i+r][j+c]-'1'])      return false;
                        vis[board[i+r][j+c]-'1'] = 1;
                    }
                }
                memset(vis,0,sizeof(vis));
            }
        }
        return true;
    }
};


