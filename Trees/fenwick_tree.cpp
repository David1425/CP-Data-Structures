template<typename T, typename OP=plus<T>>
struct fenwick_tree {
	T base=0;
	vector<T> bit;
	int size;
	OP op;
	
	fenwick_tree(int n, T def=0) : size(n) {
		bit.resize(n+1);
		fill(bit.begin(), bit.end(), def);
	}
	
	void build(vector<T> vec) {
		int s = int(vec.size());
		for (int i = 1; i <= s; i++) {
			bit[i] = op(bit[i], vec[i-1]);
			int x = i + (i&-i);
			if (x <= s) bit[x] = op(bit[x], bit[i]);
		}
	}
	
	void update(int i, T v) {
		for (; i <= size; i += i&-i) bit[i] = op(bit[i], v);
	}
	void rupdate(int i, T v) {
		for (; i > 0; i -= i&-i) bit[i] = op(bit[i], v);
	}
	
	T query(int i) {
		T r = base;
		for (; i > 0; i -= i&-i) r = op(r, bit[i]);
		return r;
	}
	T rquery(int i) {
		T r = base;
		for (; i <= size; i += i&-i) r = op(r, bit[i]);
		return r;
	}
};
