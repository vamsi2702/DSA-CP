void dfs(int node,int parent,int depth){
    dep[node]=depth;
    par[node]=parent;
    subtreesz[node]=1;
    numchild[node]=0;
    for(auto neigh:neighbours(node)){
        if(neigh!=parent){
            dfs(neigh,node,depth+1);
            subtreesz[node]+=subtreesz[neigh];
            numchild[node]++;
        }
    }
    if (numchild[node]==0){
        isleaf[node]=1;
    }
}