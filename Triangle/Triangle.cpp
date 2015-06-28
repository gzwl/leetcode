/*
    triangle原来是每个点的数值，我们现在把它当做从根到该点所能取得的最大值
    然后进行dp
*/

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.size() == 0)    return 0;
        for(int i = 1;i < triangle.size();i++)
        {
            for(int j = 0;j < triangle[i].size();j++)
            {
                if(j == 0)  triangle[i][j] += triangle[i-1][j];         //只能从右上角来
                else if(j == triangle[i].size() - 1)  triangle[i][j] += triangle[i-1][j-1];     //只能从左上角来
                else    triangle[i][j] += min(triangle[i-1][j-1],triangle[i-1][j]);             //从两个方向取最小的
            }
        }
        int res = triangle[triangle.size()-1][0];
        for(int i = 1;i < triangle[triangle.size()-1].size();i++){
            res = min(res,triangle[triangle.size()-1][i]);
        }
        return res;
    }
};

