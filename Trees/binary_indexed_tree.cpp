template <typename T>
class binary_indexed_tree {
    
    // Define calculation used in build() and update()
    T (*calc)(T, T) = [](T a, T b) {
        return a+b;
    };
    
    // Define inverse calculation used in range query()
    T (*inv)(T, T) = [](T a, T b) {
        return a-b;
    };
    
    // Return a value to start with during query()
    T base = 0;
    
    public:
    vector<T> bit;
    int size;
    
    binary_indexed_tree(int n, int def = 0) : size(n) { // def sets base values
        bit.assign(n+1, def);
    }
    
    void setCalc(T (*func)(T, T)) { calc=func; } // Used to change calc function - e.g. a+b for Range Sum Query, a*b for Range Product Query
    void setInv(T (*func)(T, T)) { inv=func; } // Used to change inv function - e.g. a-b for Range Sum Query, a/b for Range Product Query
    void setBase(T val) { base=val; } // Used to change base value - e.g. 0 for Range Sum Query, 1 for Range Product Query
    
    void update(int ind, T v) {
        ind++;
        for (; ind <= size; ind += ind&-ind) {
            bit[ind] = calc(bit[ind], v);
        }
    }
    
    void build(vector<T> vec) {
        for (int i = 0; i < vec.size(); i++) {
            update(i, vec[i]);
        }
    }
    
    T query(int pos) {
        pos++;
        T res = base;
        for (; pos > 0; pos -= pos&-pos) {
            res = calc(res, bit[pos]);
        }
        return res;
    }
    
    T query(int l, int r) {
        if (l == 0) return query(r);
        return inv(query(r), query(l-1));
    }
};
