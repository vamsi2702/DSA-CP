void dfs(int st, int n_comp) {
    vis[st] = n_comp;
    for (auto node : g[st]) {
        if (!vis[node]) {
            dfs(node, n_comp);
        } 
    }
}