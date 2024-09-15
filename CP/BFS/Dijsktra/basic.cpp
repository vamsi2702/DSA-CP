#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<pair<int,int>>>g;
const int inf = 1e9;
#define F first
#define S second
vector<int>vis;
vector<int>dis;
void sssp(int sc){
    vis.assign(n+1,0);
    dis.assign(n+1,inf);
    priority_queue<pair<int,int>>q;
    dis[sc]=0;
    q.push({0,sc});
    
    while(!q.empty()){
        int x = q.top().second;
        q.pop();
    
        if(vis[x]) continue;
        vis[x]=1;
        
        for(auto neighs: g[x]){
            if(dis[neighs.F]>dis[x]+neighs.S){ 
               dis[neighs.F]=dis[x]+neighs.S;
               q.push({-dis[neighs.F],neighs.F}); 
            }
        }
    }
}

int main(){
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
        int sc;
        cin>>sc;
        sssp(sc);
        
    }
}