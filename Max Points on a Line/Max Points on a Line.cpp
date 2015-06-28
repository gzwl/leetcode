/*
    在同一直线上的点斜率相同，那么我们先O(n)枚举每个点，再O(n)枚举其它点和它的斜率，这样斜率相同的点就在一条直线上
    但由于浮点数的计算误差和0的因素，所以存的是斜率的dx和dy(dx和dy是经过处理的，详见代码)
    这样时间复杂度是O(n^2)
*/

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        typedef pair<int,int> P;
        if(points.size() == 1 || points.size() == 0)    return points.size();
        int res = 0;
        for(int i = 0;i < points.size();i++){
            map<P,int> cnt;                             //pair存dx和dy，int存这个斜率出现的次数
            int maxval = 0;                             //有i的直线的最多共线点个数
            for(int j = i + 1;j < points.size();j++){
                int dx = points[i].x - points[j].x;
                int dy = points[i].y - points[j].y;
                if(dx == 0 && dy == 0){                 //如果i和j在一个位置上，那么j可以加到任意有i直线上，所以统计时都要加上cnt[P(0,0)]
                    cnt[P(0,0)]++;
                    maxval++;
                }
                else if(dx == 0){                                       //dx == 0 && dy != 0 统一用(0,1)表示
                    maxval = max(maxval,++cnt[P(0,1)] + cnt[P(0,0)]);
                }
                else if(dy == 0){                                       //dx != 0 && dy == 0 统一用(1,0)表示
                    maxval = max(maxval,++cnt[P(1,0)] + cnt[P(0,0)]);
                }
                else{                                                   //dx与dy如果同号都取正，否则dx取负
                    if(dx * dy < 0){
                        dx = -abs(dx);dy = abs(dy);
                    }
                    else{
                        dx = abs(dx);dy = abs(dy);
                    }
                    int tmp = gcd(abs(dx),abs(dy));                     //求dx和dy的最大公约数
                    dx /= tmp;
                    dy /= tmp;
                    maxval = max(maxval,++cnt[P(dx,dy)] + cnt[P(0,0)]);
                }
            }
            res = max(res,maxval);
        }
        return res + 1;
    }
    int gcd(int x,int y)
    {
        if(y == 0)  return x;
        else    return gcd(y,x%y);
    }
};

