vector<pair<int, int>> lca_depth;
void lca_dfs(int u, int p, int d) {
    lca_depth.push_back({d, u});
    for (auto v : adj[u]) {
        if (v != p) {
            lca_dfs(v, u, d+1);
            lca_depth.push_back({d, u});
        }
    }
}
