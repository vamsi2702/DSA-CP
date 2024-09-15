#include <bits/stdc++.h>
using namespace std;
using state =pair<int,int>;
const int inf =1e9;
#define F first
#define S second
vector<vector<int>>vis;
vector<vector<int>>dis;
int n,m;
vector<vector<char>>arr;

bool is_valid(int x, int y){
    if(x>=0&&x<n&&y>=0&&y<m&&arr[x][y]!='#'){
        return 1;
    }
    return 0;
}

vector<state> neighbours(state node){
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    vector<state>ans;
    for(int k=0;k<4;k++){
        int x = node.F+dx[k];
        int y = node.S+dy[k];
        if(is_valid(x,y)){
            ans.push_back({x,y});
        } 
    }
    return ans;
}
void bfs(state node){
    vis.assign(n,vector<int>(m,0));
    dis.assign(n,vector<int>(m,inf));
    
    queue<state>q;
    dis[node.F][node.S]=0;
    q.push(node);
    
    while(!q.empty()){
        state x = q.front();
        q.pop();
        
        if(vis[x.F][x.S]) continue;
        vis[x.F][x.S]=1;
        
        for(auto neighs:neighbours(x)){
            if(dis[neighs.F][neighs.S]>dis[x.F][x.S]+1){
                dis[neighs.F][neighs.S]=dis[x.F][x.S]+1;
                q.push(neighs);
            }
        }
        
    }
    
}

int main(){
    
    cin>>n>>m;
    arr.resize(n);
    state st,en;
    for(int i=0;i<n;i++){
        arr[i].resize(m);
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='S'){
                st ={i,j};
            }
            if(arr[i][j]=='F'){
                en ={i,j};
            }
            
        }
    }
    
    
    bfs(st);
    cout<<dis[en.F][en.S]<<endl;
    
    
}