//TC = O(n) single pass
//SC = o(n)
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(false);
#define print(array)      \
    for (auto it : array) \
    cout << it << " "
#define sortit(array) sort(array.begin(), array.end())
const int M = 1e9 + 7;

int largestRectangleArea(vector<int> &heights)
{
    stack<int> st;
    int maxarea = 0;
    int width = 0;
    int n = heights.size();
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
        {
            int height = heights[st.top()];
            st.pop();
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            maxarea = max(maxarea, width * height);
        }
        st.push(i);
    }
    return maxarea;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(heights);
}
