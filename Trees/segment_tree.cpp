template<typename T, typename OP=plus<T>>
class segment_tree {
	int lg2(int x) { return 31 - __builtin_clz(x); }
	
	OP op;
	T base;
	int mx;
	vector<T> st;
	
	void build(int i, int l, int r, const vector<T> &o) {
		if (l == r) {
			if (l < int(o.size())) st[i] = o[l];
			return;
		}
		
		int mid = (l+r)/2;
		build(i*2, l, mid, o);
		build(i*2+1, mid+1, r, o);
		st[i] = op(st[i*2], st[i*2+1]);
	}
	
	void update(int ind, T v, int i, int l, int r) {
		if (l == r) {
			st[i] = v;
			return;
		}
		
		int mid = (l+r)/2;
		if (ind <= mid) update(ind, v, i*2, l, mid);
		else update(ind, v, i*2+1, mid+1, r);
		st[i] = op(st[i*2], st[i*2+1]);
	}
	
	T query(int lx, int rx, int i, int l, int r) {
		if (r < lx || l > rx) return base;
		if (l >= lx && r <= rx) return st[i];
		int mid = (l+r)/2;
		T a = query(lx, rx, i*2, l, mid);
		T b = query(lx, rx, i*2+1, mid+1, r);
		return op(a, b);
	}
	
public:
	segment_tree(int n, T def=0) : mx(n), base(def) { st.assign((1<<(lg2(n-1)+2))+5, def); }
	
	void build(const vector<T> &o) { build(1, 0, mx-1, o); }
	void update(int x, T v) { update(x, v, 1, 0, mx-1); }
	T query(int lx, int rx) { return query(lx, rx, 1, 0, mx-1); }
};
