// 0-indexed segment tree
template <typename T>
class segment_tree {
    vector<T> o;
    
    // Define calculation used in build() and update()
    T (*calc)(T, T) = [](T a, T b) {
        return min(a, b);
    };
    
    // Return some value during query() when not in range
    T (*base)() = []() {
        return T(2e9);
    };
    
    void build(int i, int l, int r) {
        if (l == r) {
            if (l < int(o.size())) st[i] = o[l];
            return;
        }
        
        int mid = (l+r)/2;
        build(i*2, l, mid);
        build(i*2+1, mid+1, r);
        st[i] = calc(st[i*2], st[i*2+1]);
    }
    
    void update(int ind, T v, int i, int l, int r) {
        if (l == r) {
            st[i] = v;
            return;
        }
        
        int mid = (l+r)/2;
        if (ind <= mid) update(ind, v, i*2, l, mid);
        else update(ind, v, i*2+1, mid+1, r);
        st[i] = calc(st[i*2], st[i*2+1]);
    }
    
    T query(int lx, int rx, int i, int l, int r) {
        if (r < lx || l > rx) return base();
        if (l >= lx && r <= rx) return st[i];
        int mid = (l+r)/2;
        T a = query(lx, rx, i*2, l, mid);
        T b = query(lx, rx, i*2+1, mid+1, r);
        return calc(a, b);
    }
    
    public:
    vector<T> st;
    int size;
    
    segment_tree(int n) : size(n) { st.assign(1<<(int(ceil(log2(n)))+1), 0); }
    
    void setCalc(T (*func)(T, T)) { calc=func; } // Used to change calc function - e.g. min(a, b) for Range Minimum Query, a+b for Range Sum Query
    void setBase(T (*func)()) { base=func; } // Used to change base function - e.g. INT_MAX or LONG_MAX for Range Minimum Query, 0 for Range Sum Query
    
    void build(vector<T> v) { o=v; build(1, 0, size-1); } // Build initial segment tree
    
    void update(int ind, T v) { update(ind, v, 1, 0, size-1); } // Update element at ind to v
    
    T query(int l, int r) { return query(l, r, 1, 0, size-1); } // Query range [l, r]
};
