vector<long long> depth;
int pos[MM];
void lca_dfs(int u, int p, ll d) {
	if (pos[u] == -1) pos[u] = int(depth.size());
	depth.push_back(d);
	for (auto v, : adj[u]) {
		if (v != p) {
			lca_dfs(v, u, d+1);
			depth.push_back(d);
		}
	}
}
