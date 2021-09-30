template<typename T, typename U>
T fpow(T a, U b) {
    T x = 1;
    while (b > 0) {
        if (b&1) x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}

template<typename T, typename U, typename V>
T fpow(T a, U b, V m) {
    T x = 1;
    while (b > 0) {
        if (b&1) x = (x*a)%m;
        a = (a*a)%m;
        b >>= 1;
    }
    return x;
}
