template<typename T, typename OP=plus<T>>
class segment_tree_lazy {
	int lg2(int x) { return 31 - __builtin_clz(x); }
	
	OP op;
	int mx;
	T base, emp;
	vector<T> st, lazy;
	
	void push(int i, int l, int r) {
		if (lazy[i] == emp) return;
		if (l == r) {
			st[i] = lazy[i];
			lazy[i] = emp;
			return;
		}
		
		// Change according to problem
		st[i] = op(st[i], lazy[i]*(r-l+1));
		lazy[i<<1] = lazy[i];
		lazy[(i<<1)+1] = lazy[i];
		lazy[i] = emp;
	}
	
	void build(int i, int l, int r, const vector<T> &o) {
		if (l == r) {
			if (l < int(o.size())) st[i] = o[l];
			return;
		}
		
		int mid = (l+r)>>1;
		build(i<<1, l, mid, o);
		build((i<<1)+1, mid+1, r, o);
		st[i] = op(st[i<<1], st[(i<<1)+1]);
	}
	
	void update(int lx, int rx, T v, int i, int l, int r) {
		if (lx <= l && r <= rx) {
			lazy[i] = v;
			push(i, l, r);
			return;
		}
		push(i, l, r);
		
		int mid = (l+r)>>1;
		if (lx <= mid) update(lx, rx, v, i<<1, l, mid);
		if (rx > mid) update(lx, rx, v, (i<<1)+1, mid+1, r);
		st[i] = op(st[i<<1], st[(i<<1)+1]);
	}
	
	T query(int lx, int rx, int i, int l, int r) {
		push(i, l, r);
		if (r < lx || l > rx) return base;
		if (l >= lx && r <= rx) return st[i];
		int mid = (l+r)>>1;
		T a = query(lx, rx, i<<1, l, mid);
		T b = query(lx, rx, (i<<1)+1, mid+1, r);
		return op(a, b);
	}
	
public:
	segment_tree(int n, T def=0, T laz=-2e9) : mx(n), base(def), emp(laz) {
		st.assign((1<<(lg2(n-1)+2))+5, def);
		lazy.assign((1<<(lg2(n-1)+2))+5, laz);
	}
	
	void build(const vector<T> &o) { build(1, 0, mx-1, o); }
	void update(int x, T v) { update(x, x, v, 1, 0, mx-1); }
	void update(int lx, int rx, T v) { update(lx, rx, v, 1, 0, mx-1); }
	T query(int x) { return query(x, x, 1, 0, mx-1); }
	T query(int lx, int rx) { return query(lx, rx, 1, 0, mx-1); }
};
