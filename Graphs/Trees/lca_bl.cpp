vector<int> par[30], depth;
void lca_dfs(int u=1, int p=0) {
	depth[u] = depth[p]+1;
	par[u][0] = p;
	for (int i = 1; (1<<i) < depth[u]; i++) par[u][i] = par[par[u][i-1]][i-1];
	for (auto x : adj[u]) if (x.v != p) lca_dfs(x.v, u);
}
