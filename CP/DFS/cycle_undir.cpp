void dfs(int st, int par) {
    vis[st] = 1;
    for (auto node : g[st]) {
        if (!vis[node]) {
            dfs(node, st);
        } else if (node != par) { // Change from node != st to node != par
            is_cycle = true;
        }
    }
}