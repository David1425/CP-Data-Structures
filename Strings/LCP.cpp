vector<int> build_lcp(string s, vector<int> p) {
	int n = sz(s);
	vector<int> pos(n), lcp(n-1);
	for (int i = 0; i < n; i++) pos[p[i]] = i;
	int len = 0;
	for (int i = 0; i < n; i++) {
		if (pos[i] == n-1) len = 0;
		else {
			int j = p[pos[i]+1];
			while (i+len < n && j+len < n && s[i+len]==s[j+len]) len++;
			lcp[pos[i]] = len;
		}
		if (len) len--;
	}
	return lcp;
}
