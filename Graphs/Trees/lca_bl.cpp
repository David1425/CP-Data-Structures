vector<int> par[20], depth;
void lca_dfs(int u=1) {
	for (int i = 1; i < 20; i++) par[i][u] = par[i-1][par[i-1][u]];
	for (auto x : adj[u]) if (x.v != par[0][u]) {
		par[0][x.v] = u;
		depth[x.v] = depth[u]+1;
		lca_dfs(x.v);
	}
}
