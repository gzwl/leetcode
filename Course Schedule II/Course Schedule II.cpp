//根据I的程序修改一下即可
vector<int> G[1000];
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        int *in = new int[numCourses];
        for(int i = 0;i < numCourses;i++){
            in[i] = 0;
            G[i].clear();
        }
        queue<int> q;
        for(int i = 0;i < prerequisites.size();i++){
            int u = prerequisites[i].second;
            int v = prerequisites[i].first;
            in[v]++;
            G[u].push_back(v);
        }
        int cnt = 0;
        for(int i = 0;i < numCourses;i++)   if(!in[i]){
            q.push(i);
            cnt++;
            res.push_back(i);
        }
        while(q.size()){
            int u = q.front();q.pop();
            for(int i = 0;i < G[u].size();i++){
                int v = G[u][i];
                if(--in[v] == 0){
                    q.push(v);
                    cnt++;
                    res.push_back(v);
                }
            }
        }
        delete [] in;
        if(cnt == numCourses)   return res;
        else{
            res.clear();return res;
        }
    }
};
