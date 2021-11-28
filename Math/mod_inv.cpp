void exgcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    long long x1 = x, y1 = y;
    exgcd(b, a%b, x1, y1);
    y = x1 - (a/b)*y1;
    x = y1;
}

long long modInv(long long a, long long m) {
    long long x, y;
    if (a < m) exgcd(a, m, x, y);
    else exgcd(m, a, x, y);
    return (x%m+m)%m;
}
