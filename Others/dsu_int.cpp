class DSU {
    public:
    vector<int> size;
    vector<int> par;
    int MX;
    
    DSU() {}
    DSU(int n) : MX(n+2) {
        size.assign(MX, 1);
        par.assign(MX, -1);
    }
    
    void clear() {
        size.assign(MX, 1);
        par.assign(MX, -1);
    }
    
    int find(int x) {
        if (par[x] == -1) return x;
        par[x] = find(par[x]);
        return par[x];
    }
    
    void merge(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        if (size[x] >= size[y]) par[y] = x, size[x] += size[y];
        else par[x] = y, size[y] += size[x];
    }
};
