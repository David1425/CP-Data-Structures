template <typename T = long long>
struct matrix {
    vector<vector<T>> mat;
    int h, w;
    
    //-- Matrix constructors --//
    matrix(int h=1, int w=1, T v=0, bool d=0) : h(h), w(w) {
        if(!d) mat.assign(h, vector<T>(w, v));
        else {
            mat.assign(h, vector<T>(w, 0));
            for (int i = 0; i < min(h, w); i++) mat[i][i] = v;
        }
    }
    template <typename U>
    matrix(matrix<U> m) {
        h = m.h; w = m.w;
        mat.resize(h);
        for (int i = 0; i < h; i++) {
            mat[i] = vector<T>(m(i).begin(), m(i).end());
        }
    }
    template <typename U> matrix(vector<vector<U>> vec) { init(vec); }
    template <typename U>
    matrix(initializer_list<initializer_list<U>> lis) {
        vector<vector<U>> t_vec;
        for (auto i : lis) {
            t_vec.emplace_back(vector<U>(i));
        }
        init(t_vec);
    }
    
    template <typename U>
    void init(vector<vector<U>> vec) {
        h = vec.size();
        w = vec[0].size();
        mat.resize(vec.size());
        for (int i = 0; i < vec.size(); i++) {
            mat[i] = vector<T>(vec[i].begin(), vec[i].end());
        }
    }
    
    //-- Assignment functions --//
    template <typename U>
    void fill(U x) { mat.assign(h, vector<T>(w, T(x))); }
    
    template <typename U>
    void fill_d(U x) { for(int i=0;i<min(h,w);i++)mat[i][i]=x; }
    
    //-- Math functions --//
    template <typename U>
    matrix<T> pow(U b) {
        b--;
        matrix<T> a(*this), res(*this);
        while (b > 0) {
            if (b&1) res = res*a;
            a = a*a;
            b >>= 1;
        }
        
        return res;
    }
    
    T sum(int rs = 0, int cs = 0, int rt = -1, int ct = -1) {
        if (rt == -1) rt = h-1;
        if (ct == -1) ct = w-1;
        T res = 0;
        for (int i = rs; i <= rt; i++) {
            for (int j = cs; j <= ct; j++) {
                res = (res+mat[i][j])%MOD;
            }
        }
        return res;
    }
    
    /*T determinant() {
        WIP
    }*/
    
    //-- Index operators --//
    T& operator () (int r, int c) { return mat[r][c]; }
    vector<T>& operator () (int r) { return mat[r]; }
    
    //--- Arithmetic operators --//
    template <typename U>
    void operator = (vector<vector<U>> vec) { *this = matrix(vec); }
    template <typename U>
    void operator = (initializer_list<initializer_list<U>> lis) { *this = matrix(lis); }
    
    matrix<T> operator + (matrix<T> m) {
        int x = m.w, y = m.h;
        assert(w == x && h == y);
        matrix<T> tmp(h, w);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                tmp(i, j) = (mat[i][j] + m(i, j))%MOD;
            }
        }
        return tmp;
    }
    
    matrix<T> operator - (matrix<T> m) {
        int x = m.w, y = m.h;
        assert(w == x && h == y);
        matrix<T> tmp(h, w);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                tmp(i, j) = (mat[i][j] - m(i, j)+MOD)%MOD;
            }
        }
        return tmp;
    }
    
    matrix<T> operator * (matrix<T> m) {
        int x = m.w, y = m.h;
        assert(w == y);
        matrix<T> tmp(h, x);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                for (int k = 0; k < x; k++) {
                    tmp(i, k) = (tmp(i, k) + (mat[i][j]*m(j, k))%MOD)%MOD;
                }
            }
        }
        
        return tmp;
    }
    
    //-- I/O stream operators --//
    friend istream& operator >> (istream& is, matrix<T>& m) {
        for (auto& i : m.mat) for (auto& j : i) is>>j;
        return is;
    }
    
    friend ostream& operator << (ostream& os, matrix<T> m) {
        os << "[\n";
        for (auto i : m.mat) {
            os << "[";
            for (int j = 0; j < m.w; j++) os << i[j] << ((j < m.w-1) ? ", " : "]\n");
        }
        os << "]\n";
        return os;
    }
};
