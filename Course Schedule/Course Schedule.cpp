/*
    这道题其实就是通过拓扑排序来判断一个有向图有没有环
*/



//边表做法，比较慢
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int *in = new int[numCourses];
        for(int i = 0;i < numCourses;i++)   in[i] = 0;
        queue<int> q;
        for(int i = 0;i < prerequisites.size();i++){
            in[prerequisites[i].first]++;
        }
        int cnt = 0;
        for(int i = 0;i < numCourses;i++)   if(!in[i]){
            q.push(i);
            cnt++;
        }
        while(q.size()){
            int u = q.front();q.pop();
            for(int i = 0;i < prerequisites.size();i++){
                if(prerequisites[i].second == u){
                    int v = prerequisites[i].first;
                    if(--in[v] == 0){
                        q.push(v);
                        cnt++;
                    }
                }
            }
        }
        delete [] in;
        if(cnt == numCourses)   return true;
        else    return false;
    }
};




//临接表做法，要快很多
vector<int> G[1000];
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
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
        }
        while(q.size()){
            int u = q.front();q.pop();
            for(int i = 0;i < G[u].size();i++){
                int v = G[u][i];
                if(--in[v] == 0){
                    q.push(v);
                    cnt++;
                }
            }
        }
        delete [] in;
        if(cnt == numCourses)   return true;
        else    return false;
    }
};
