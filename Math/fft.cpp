void FFT(complex<double> *P, int n) {
    if (n == 1) return;
    int s = n>>1;
    complex<double> Pe[s], Po[s];
    for (int i = 0; i < s; i++) {
        Pe[i] = P[i<<1];
        Po[i] = P[(i<<1)+1];
    }
    
    FFT(Pe, s); FFT(Po, s);
    double m = 2*M_PI/n;
    complex<double> w(cos(m), sin(m)), pw(1, 0);
    for (int i = 0; i <s; i++) {
        P[i] = Pe[i] + pw*Po[i];
        P[i+s] = Pe[i] - pw*Po[i];
        pw *= w;
    }
}

void IFFT(complex<double> *P, int n) {
    if (n == 1) return;
    int s = n>>1;
    complex<double> Pe[s], Po[s];
    for (int i = 0; i < s; i++) {
        Pe[i] = P[(i<<1)];
        Po[i] = P[(i<<1)+1];
    }
    
    IFFT(Pe, s); IFFT(Po, s);
    double m = -2*M_PI/n;
    complex<double> w(cos(m), sin(m)), pw(1, 0);
    for (int i = 0; i < s; i++) {
        P[i] = (Pe[i] + pw*Po[i])/complex<double>(2);
        P[i+s] = (Pe[i] - pw*Po[i])/complex<double>(2);
        pw *= w;
    }
}

vector<int> FFTmult(vector<int> a, vector<int> b) { // Polynomial multiplication
    int n = 1;
    while (int(a.size()) + int(b.size()) > n) n <<= 1;
    a.resize(n); b.resize(n);
    
    complex<double> x[a.size()], y[b.size()];
    for (int i = 0; i < a.size(); i++) x[i] = a[i];
    for (int i = 0; i < b.size(); i++) y[i] = b[i];
    FFT(x, n); FFT(y, n);
    for (int i = 0; i < n; i++) x[i] *= y[i];
    IFFT(x, n);
    
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        r[i] = round(x[i].real());
    }
    return r;
}

vector<int> mult(string x, string y) { // Large number multiplication
    vector<int> a(x.size()), b(y.size());
    for (int i = 0; i < int(x.size()); i++) a[i] = x[i]-'0';
    for (int i = 0; i < int(y.size()); i++) b[i] = y[i]-'0';
    reverse(a.begin(), a.end()); reverse(b.begin(), b.end());
    
    vector<int> r = FFTmult(a, b);
    
    for (int i = 0; i < int(r.size()); i++) {
        int x = r[i];
        if (x >= 10) {
            if (i == int(r.size())-1) r.push_back(x/10);
            else r[i+1] += x/10;
        }
        r[i] = x%10;
    }
    reverse(r.begin(), r.end());
    
    vector<int> ans;
    bool f = 0;
    for (int i : r) {
        if (i == 0 && !f) continue;
        f = 1;
        ans.push_back(i);
    }
    return ans;
}
