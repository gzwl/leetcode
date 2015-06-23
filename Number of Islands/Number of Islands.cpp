/*
    每次搜索到一个陆地就通过dfs把与这个点相连的所有陆地都找出来
    注意要记忆访问过的地方，避免重复搜素
*/

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = n ? grid[0].size() : 0;
        int **vis = new int*[n];
        for(int i = 0;i < n;i++){
            vis[i] = new int[m];
            for(int j = 0;j < m;j++)    vis[i][j] = 0;  //vis[i][j]表示(i,j)是否被搜索过
        }
        int res = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    res++;
                    dfs(grid,vis,i,j,n,m);
                }
            }
        }
        for(int i = 0;i < n;i++)    delete [] dp[i];
        delete dp;
        return res;
    }
    void dfs(vector<vector<char>>& grid,int **vis,int x,int y,int n,int m)
    {
        vis[x][y] = 1;
        for(int i = 0;i < 4;i++){       //往上下左右四个方向搜索
            int xt = x + dx[i];
            int yt = y + dy[i];
            if(xt >= 0 && xt < n && yt >= 0 && yt < m && grid[xt][yt] == '1' && !vis[xt][yt]){
                dfs(grid,vis,xt,yt,n,m);
            }
        }
    }
};
