template<typename T>
class DSU { // Works for any types but a bit slower because of unordered_map
    public:
    unordered_map<T, int> rank;
    unordered_map<T, T> par;
    
    DSU() {}
    
    T find(T x) {
        if (par.find(x) == par.end()) return x;
        par[x] = find(par[x]);
        return par[x];
    }
    
    void merge(T a, T b) {
        T x = find(a), y = find(b);
        if (x == y) return;
        if (rank[x] > rank[y]) par[y] = x;
        else if (rank[x] < rank[y]) par[x] = y;
        else {
            par[y] = x;
            rank[x]++;
        }
    }
};
