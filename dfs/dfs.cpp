    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited,int i,int j,int n, int m)
    {
         visited[i][j]=1;
         for(int k = 0;k < 4;k++){
            int it=i+dx[k];
            int jt=j+dy[k];
            if(it >= 0 && it < n && jt >= 0 && jt < m && grid[it][jt] == '1' && !visited[it][jt]){
                dfs(grid,visited,it,jt,n,m);
            }
         } 
    }
