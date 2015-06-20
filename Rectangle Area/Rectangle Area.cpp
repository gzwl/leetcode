class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int height = 0,wide = 0;
        if(D > F && H > B){
            height = min(D,H) - max(F,B);
        }
        if(C > E && G > A){
            wide = min(C,G) - max(E,A);
        }
        int s1 = (C - A) * (D - B);
        int s2 = (G - E) * (H - F);
        int s3 = height * wide;
        return s1 + s2 - s3;
    }
};
