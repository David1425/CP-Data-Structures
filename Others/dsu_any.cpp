template<typename T>
class DSU {
    public:
    unordered_map<T, int> size;
    unordered_map<T, T> par;
    
    DSU() {}
    
    void clear() {
        size.clear();
        par.clear();
    }
    
    T find(T x) {
        if (par.find(x) == par.end()) return x;
        par[x] = find(par[x]);
        return par[x];
    }
    
    void merge(T a, T b) {
        T x = find(a), y = find(b);
        if (x == y) return;
        if (!size[x]) size[x] = 1;
        if (!size[y]) size[y] = 1;
        if (size[x] >= size[y]) par[y] = x, size[x]+=size[y];
        else par[x] = y, size[y]+=size[x];
    }
};
