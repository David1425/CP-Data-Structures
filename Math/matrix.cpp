template <typename T>
class matrix {
    vector<vector<T>> mat;
    int h, w;
    T md = -1;
    
    matrix(int h, int w) : h(h), w(w) { mat.assign(h, vector<T>(w, 0)); }
    matrix(vector<vector<T>> vec) {
        h = vec.size();
        w = vec[0].size();
        mat = vec;
    }
    
    matrix pow(long long b, matrix res) { // matrix exponentiation
        matrix a = mat;
        while (b > 0) {
            if (b&1) res = res*a;
            a = a*a;
            b >>= 1;
        }
        
        return res;
    }
    
    T& operator () (int r, int c) { return mat[r][c]; }
    vector<T>& operator () (int r) { return mat[r]; }
    
    void operator = (vector<vector<T>> vec) {
        h = vec.size();
        w = vec[0].size();
        mat = vec;
    }
    
    matrix operator * (matrix m) {
        int x = m.w;
        int y = m.h;
        assert(w == y);
        matrix tmp(h, x);
        if (md != -1) {
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    for (int k = 0; k < x; k++) {
                        tmp(i, k) = (tmp(i, k) + (mat[i][j]*m(j, k))%md )%md;
                    }
                }
            }
        } else {
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    for (int k = 0; k < x; k++) {
                        tmp(i, k) += mat[i][j]*m(j, k);
                    }
                }
            }
        }
        
        return tmp;
    }
    
    matrix operator * (vector<vector<T>> m) {
        return (*this) * matrix(m);
    }
    
    friend ostream& operator << (ostream& os, matrix m) {
        cout << "{\n";
        for (auto i : m.mat) {
            cout << "{";
            for (int j = 0; j < m.w; j++) os << i[j] << ((j < m.w-1) ? ", " : "}\n");
        }
        cout << "}\n";
        return os;
    }
};
