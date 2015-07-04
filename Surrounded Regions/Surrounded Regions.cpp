/*
    因为没有被包围的区域一定有点在边缘，所以我们从矩形的4条边开始bfs,能搜到的'O‘改为’1‘,表示没有被包围
    最后在遍历一遍矩形，原来是’1‘的改为’O‘,原来是’O‘的改为’X‘
    另外此题不能用dfs！！！ 会栈溢出
*/

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = n ? board[0].size() : 0;
        for(int i = 0;i < n;i++){
            if(board[i][0] == 'O'){
                bfs(board,i,0,n,m);
            }
            if(board[i][m-1] == 'O'){
                bfs(board,i,m-1,n,m);
            }
        }
        for(int i = 0;i < m;i++){
            if(board[0][i] == 'O'){
                bfs(board,0,i,n,m);
            }
            if(board[n-1][i] == 'O'){
                bfs(board,n-1,i,n,m);
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(board[i][j] == '1')  board[i][j] = 'O';
                else if(board[i][j] == 'O')     board[i][j] = 'X';
            }
        }
    }
    void bfs(vector<vector<char>> &board,int x,int y,int n,int m)
    {
        board[x][y] = '1';
        queue<pair<int,int>> q;
        q.push(make_pair(x,y));
        while(q.size()){
            pair<int,int> p = q.front();q.pop();
            for(int i = 0;i < 4;i++){
                int xt = p.first + dx[i];
                int yt = p.second + dy[i];
                if(xt >= 0 && xt < n && yt >= 0 && yt < m && board[xt][yt] == 'O'){
                    board[xt][yt] = '1';
                    q.push(make_pair(xt,yt));
                }
            }
        }
    }
};

