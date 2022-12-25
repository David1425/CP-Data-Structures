vector<int> eulerPath() {
	vector<int> p;
	int u = 1;
	while (1) {
		p.push_back(u);
		while (!adj[u].empty() && !cnt[u][adj[u].top()]) adj[u].pop();
		if (adj[u].empty()) break;
		int v = adj[u].top();
		adj[u].pop();
		cnt[u][v]--;
		cnt[v][u]--;
		u = v;
	}
	
	return p;
}
