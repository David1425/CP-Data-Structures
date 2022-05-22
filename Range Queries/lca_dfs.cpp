vector<pair<int,int>> depth;
vector<int> pos;
void dfs(int u=1, int p=0, int d=0) {
	pos[u] = int(depth.size());
	depth.push_back({d,u});
	for (auto x : adj[u]) {
		if (x.v != p) {
			dfs(x.v, u, d+1);
			depth.push_back({d,u});
		}
	}
}
