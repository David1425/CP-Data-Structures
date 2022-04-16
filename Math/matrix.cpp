template<typename T, T mod=1000000007>
class matrix {
	vector<vector<T>> mat;
	
public:
	int h, w;
	matrix(int n=0, int m=0, T v=0) : h(n), w(m), mat(n, vector<T>(m, v)) {}
	matrix(const vector<vector<T>>& vec) : mat(vec) {
		if (vec.empty()) {
			h = 0;
			w = 0;
		} else {
			h = vec.size();
			w = vec[0].size();
		}
	}
	matrix(const vector<T>& vec) {
		if (vec.empty()) {
			h = 0;
			w = 0;
		} else {
			h = 1;
			w = vec.size();
			mat = vector<vector<T>>(1, vec);
		}
	}
	
	vector<T>& operator[] (int i) { return mat[i]; }
	
	matrix<T,mod> operator* (matrix<T,mod> m) {
		assert(w == m.h);
		matrix<T,mod> res(h, m.w, 0);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < m.w; j++) {
				for (int k = 0; k < w; k++) {
					res[i][j] += (mat[i][k] * m[k][j])%mod;
					res[i][j] %= mod;
				}
			}
		}
		return res;
	}
	
	void fillRow(int i, T x) { for (int j = 0; j < w; j++) mat[i][j] = x; }
	void fillCol(int j, T x) { for (int i = 0; i < h; i++) mat[i][j] = x; }
	T getRow(int i) {
		T res = 0;
		for (int j = 0; j < w; j++) res = (res+mat[i][j])%mod;
		return res;
	}
	T getCol(int j) {
		T res = 0;
		for (int i = 0; i < h; i++) res = (res+mat[i][j])%mod;
		return res;
	}
	
	template<typename U>
	matrix<T,mod> pow(U b) {
		assert(h==w);
		matrix<T,mod> res(h,h), a(*this);
		for (int i = 0; i < h; i++) res[i][i] = 1;
		while (b > 0) {
			if (b&1) res = res*a;
			a = a*a;
			b >>= 1;
		}
		return res;
	}
	
	friend istream& operator >> (istream& is, matrix<T,mod>& m) {
		for (auto& i : m.mat) for (auto& j : i) is>>j;
		return is;
	}
	
	friend ostream& operator << (ostream& os, matrix<T,mod> m) {
		os << "[\n";
		for (auto i : m.mat) {
			os << "[";
			for (int j = 0; j < m.w; j++) os << i[j] << ((j < m.w-1) ? ", " : "]\n");
		}
		os << "]\n";
		return os;
	}
};
