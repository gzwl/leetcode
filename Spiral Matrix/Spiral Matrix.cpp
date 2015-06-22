class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        int n = matrix.size();
        int m = n ? matrix[0].size() : 0;
        if(!n || !m)  return res;
        int x = 0,y = 0;
        int ru = 0,rd = n,rl = 0,rr = m;
        bool ok = true;
        while(1){
            ok = false;
            while(y >= rl && y < rr){
                res.push_back(matrix[x][y]);
                y++;
                ok = true;
            }
            if(!ok)     break;
            ok = false;
            y--;x++;ru++;
            while(x < rd && x >= ru){
                res.push_back(matrix[x][y]);
                x++;
                ok = true;
            }
            if(!ok)     break;
            x--;y--;rr--;
            ok = false;
            while(y >= rl && y < rr){
                res.push_back(matrix[x][y]);
                y--;
                ok = true;
            }
            if(!ok)     break;
            y++;x--;rd--;
            ok = false;
            while(x < rd && x >= ru){
                res.push_back(matrix[x][y]);
                x--;
                ok = true;
            }
            if(!ok)     break;
            x++;y++;rl++;
        }
        return res;
    }
};
