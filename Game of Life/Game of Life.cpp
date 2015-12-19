/*
    每个点其实一共有四种状态
    所以我们可以用二进制数00,01,10,11分别表示当前死下次死，当前活下次死，当前死下次活，当前活下次活4种状态
    然后就是简单的遍历和状态转化了
*/


class Solution {
private:
    int dis[8][2] = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
public:
    void gameOfLife(vector<vector<int>>& board) {

        //把0,1转化为四种状态的一种
        for(int i = 0;i < board.size();i++) {
            for(int j = 0;j < board[0].size();j++) {
                int cnt = 0;
                for(int k = 0;k < 8;k++) {
                    if(isOne(board,i + dis[k][0],j + dis[k][1]))  ++cnt;
                }
                if(board[i][j]) {
                    if(cnt < 2 || cnt > 3)     board[i][j] = 1;
                    else    board[i][j] = 3;
                }
                else if(cnt == 3)
                    board[i][j] = 2;
            }
        }

        //转换成答案,即下一次的结果
        for(int i = 0;i < board.size();i++) {
            for(int j = 0;j < board[0].size();j++) {
                if(board[i][j] <= 1)    board[i][j] = 0;
                else    board[i][j] = 1;
            }
        }
    }

    //判断这个点当前是不是活的
    bool isOne(vector<vector<int>>& board,int i,int j) {
        if(i >= 0 && i < board.size() && j >= 0 && j < board[0].size()
           && (board[i][j] == 1 || board[i][j] == 3))  return true;
        return false;
    }
};
