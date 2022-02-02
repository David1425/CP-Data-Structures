vector<ll> lca_depth;
int pos[MM];
void lca_dfs(int u, int p, ll d) {
    if (pos[u] == -1) pos[u] = int(lca_depth.size());
    lca_depth.push_back(d);
    for (auto [v, w] : adj[u]) {
        if (v != p) {
            lca_dfs(v, u, d+w);
            lca_depth.push_back(d);
        }
    }
}
