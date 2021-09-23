template <typename T = long long>
class matrix {
    public:
    vector<vector<T>> mat;
    int h, w;
    
    matrix() : h(1), w(1) { mat.assign(1, vector<T>(1, 0)); }
    matrix(int h, int w) : h(h), w(w) { mat.assign(h, vector<T>(w, 0)); }
    template <typename U>
    matrix(vector<vector<U>> vec) {
        h = vec.size();
        w = vec[0].size();
        mat.resize(vec.size());
        for (int i = 0; i < vec.size(); i++) {
            mat[i] = vector<T>(vec[i].begin(), vec[i].end());
        }
    }
    
    template <typename U>
    matrix pow(U b, matrix res) { // matrix exponentiation
        matrix a = (*this);
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
