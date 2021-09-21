long long fpow(long long a, long long b) {
    long long x = 1;
    while (b > 0) {
        if (b%2 == 1) x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}

long long fpow(long long a, long long b, long long m) {
    long long x = 1;
    while (b > 0) {
        if (b%2 == 1) x = (x*a)%m;
        a = (a*a)%m;
        b >>= 1;
    }
    return x;
}
