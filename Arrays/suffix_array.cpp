vector<int> suffix_array(string s) {
	s += '$';
	int n = int(s.size()), m = 200;
	vector<int> cnt(max(m, n)), p(n), c(n);
	for (int i = 0; i < n; i++) cnt[s[i]]++;
	for (int i = 1; i < m; i++) cnt[i] += cnt[i-1];
	for (int i = 0; i < n; i++) {
		cnt[s[i]]--;
		p[cnt[s[i]]] = i;
	}
	
	c[p[0]] = 0;
	int ind = 0;
	for (int i = 1; i < n; i++) {
		if (s[p[i]] != s[p[i-1]]) ind++;
		c[p[i]] = ind;
	}
	ind++;
	
	vector<int> pt(n), ct(n);
	for (int k = 0; (1<<k) < n; k++) {
		for (int i = 0; i < n; i++) {
			pt[i] = (p[i]-(1<<k)+n)%n;
		}
		fill(cnt.begin(), cnt.begin()+ind, 0);
		for (int i = 0; i < n; i++) cnt[c[i]]++;
		for (int i = 1; i < ind; i++) cnt[i] += cnt[i-1];
		for (int i = n-1; i >= 0; i--) {
			cnt[c[pt[i]]]--;
			p[cnt[c[pt[i]]]] = pt[i];
		}
		ct[p[0]] = 0;
		ind = 0;
		for (int i = 1; i < n; i++) {
			pair<int, int> cur = {c[p[i]], c[(p[i]+(1<<k))%n]};
			pair<int, int> prev = {c[p[i-1]], c[(p[i-1]+(1<<k))%n]};
			if (cur != prev) ind++;
			ct[p[i]] = ind;
		}
		ind++;
		c = ct;
	}
	
	p.erase(p.begin());
	return p;
}
