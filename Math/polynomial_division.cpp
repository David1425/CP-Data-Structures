template<typename T>
vector<T> polyDiv(vector<T> N, vector<T> D) {
	auto getInd = [](vector<T> v) -> T {
		for (int i = sz(v)-1; i >= 0; i--) if (v[i] != 0) return i;
		return -1;
	};
	
	vector<T> Q(N.size());
	int x, y;
	while ((x = getInd(N)) >= (y = getInd(D))) {
		// cout << x << " " << y << "\n";
		int ind = x-y;
		Q[ind] = N[x]/D[y];
		for (int i = 0; i <= y; i++) N[i+ind] -= D[i]*Q[ind];
	}
	return Q;
}
