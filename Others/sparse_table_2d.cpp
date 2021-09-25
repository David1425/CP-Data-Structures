int flog2(int x) { return 31 - __builtin_clz(x); }

public:
vector<vector<vector<vector<T>>>> tbl;
int n, m;
sparse_table_2d(){}
void build(vector<vector<T>> vec) {
    n = int(vec.size());
    m = int(vec[0].size());
    int lgn = flog2(n), lgm = flog2(m);
    tbl.assign(n, vector<vector<vector<T>>>(lgn+1, vector<vector<T>>(m, vector<T>(lgm+1))));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tbl[i][0][j][0] = vec[i][j];
        }

        for (int j = 1; j <= lgm; j++) {
            int tmp = m - (1<<(j-1));
            for (int k = 0; k < tmp; k++) {
                tbl[i][0][k][j] = (tbl[i][0][k][j-1] + tbl[i][0][k+(1<<(j-1))][j-1]);
            }
        }
    }

    for (int j = 1; j <= lgn; j++) {
        int tmp = n - (1<<(j-1));
        for (int i = 0; i < tmp; i++) {
            int t = i+(1<<(j-1));
            for (int l = 0; l <= lgm; l++) {
                for (int k = 0; k < m; k++) {
                    tbl[i][j][k][l] = (tbl[i][j-1][k][l] + tbl[t][j-1][k][l]);
                }
            }
        }
    }
}

T query(int r1, int c1, int r2, int c2) {
    int lgn = flog2(r2-r1+1), lgm = flog2(c2-c1+1);
    int a = (tbl[r1][lgn][c1][lgm] + tbl[r1][lgn][c2-(1<<lgm)+1][lgm]);
    int b = (tbl[r2-(1<<lgn)+1][lgn][c1][lgm] + tbl[r2-(1<<lgn)+1][lgn][c2-(1<<lgm)+1][lgm]);
    return (a + b);
}
