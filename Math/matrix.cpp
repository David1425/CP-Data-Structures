template <typename T = long long>
class matrix {
    public:
    vector<vector<T>> mat;
    int h, w;
    
    matrix(int h=1, int w=1, int v=0) : h(h), w(w) { mat.assign(h, vector<T>(w, 0)); for (int i=min(h,w)-1;i>=0;i--)mat[i][i]=v;}
    template <typename U>
    matrix(matrix<U> m) {
        h = m.h; w = m.w;
        mat.resize(h);
        for (int i = 0; i < h; i++) {
            mat[i] = vector<T>(m.mat[i].begin(), m.mat[i].end());
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
    
    template <typename U>
    matrix pow(U b) { // matrix exponentiation
        matrix a(*this), res(h, w, 1);
        while (b > 0) {
            if (b&1) res = res*a;
            a = a*a;
            b >>= 1;
        }
        
        return res;
    }
    
    T& operator () (int r, int c) { return mat[r][c]; }
    vector<T>& operator () (int r) { return mat[r]; }
    
    template <typename U>
    void operator = (vector<vector<U>> vec) {
        h = vec.size();
        w = vec[0].size();
        mat.resize(vec.size());
        for (int i = 0; i < vec.size(); i++) {
            mat[i] = vector<T>(vec[i].begin(), vec[i].end());
        }
    }
    
    matrix operator * (matrix m) {
        int x = m.w;
        int y = m.h;
        assert(w == y);
        matrix tmp(h, x);
            for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                for (int k = 0; k < x; k++) {
                    tmp(i, k) = (tmp(i, k) + (mat[i][j]*m(j, k))%MOD)%MOD;
                }
            }
        }
        
        return tmp;
    }
    
    template <typename U>
    matrix operator * (vector<vector<U>> m) {
        return (*this) * matrix(m);
    }
    
    friend istream& operator >> (istream& is, matrix& m) {
        for (auto& i : m.mat) { for (auto& j : i) { is>>j; } }
        return is;
    }
    
    friend ostream& operator << (ostream& os, matrix m) {
        os << "[\n";
        for (auto i : m.mat) {
            os << "[";
            for (int j = 0; j < m.w; j++) os << i[j] << ((j < m.w-1) ? ", " : "]\n");
        }
        os << "]\n";
        return os;
    }
};
