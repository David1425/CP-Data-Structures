vi s(MM);
vector<bool> vis(MM);
void dfs1(int u, int p) {
	s[u] = 1;
	for (auto [v,w] : adj[u]) {
		if (v != p && !vis[v]) {
			dfs1(v,u);
			s[u] += s[v];
		}
	}
}

int centroid(int u, int p, int x) {
	for (auto [v,w] : adj[u]) {
		if (!vis[v] && v != p && s[v]*2 > x) return centroid(v,u,x);
	}
	return u;
}

vi tmp;
void dfs2(int u, int p, int d) {
	tmp.pb(d);
	for (auto [v,w] : adj[u]) {
		if (v != p && !vis[v]) {
			dfs2(v, u, d+w);
		}
	}
}

vi par(MM,-1);

void centDecomp(int u, int p) {
	dfs1(u,p);
	u = centroid(u,-1,s[u]);
	par[u] = p;
	vis[u] = 1;
	
	vi vec;
	for (auto [v,w] : adj[u]) {
		if (!vis[v]) {
			tmp.clear();
			dfs2(v,u,w);
			for (int i = 0; i < sz(tmp); i++) vec.pb(tmp[i]);
			
		}
	}
	
	for (auto [v,w] : adj[u]) if (!vis[v]) centDecomp(v,u);
}