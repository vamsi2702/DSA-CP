void dfs(int v,int par) {
	parent[v] = par;
	color[v] = 1;
	for (auto x : adj[v]) {
		if (color[x] == 1) {
            if(!f){
                int temp = v;
                while(temp!=x){
                    cycle.push_back(temp);
                    temp = parent[temp];
                }
                cycle.push_back(x);
            }
			f = true;
			return;
		}
		if (color[x] == 0) {
			dfs(x);
		}
	}
	color[v] = 2; 
}