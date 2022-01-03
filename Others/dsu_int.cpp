class DSU {
    public:
    vector<int> rank;
    vector<int> par;
    int MX;
    
    DSU() {}
    DSU(int n) : MX(n+2) {
        rank.assign(n+2, 0);
        par.assign(n+2, -1);
    }
    
    void clear() {
        rank.assign(MX, 0);
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
        if (rank[x] > rank[y]) par[y] = x;
        else if (rank[x] < rank[y]) par[x] = y;
        else {
            par[y] = x;
            rank[x]++;
        }
    }
};
