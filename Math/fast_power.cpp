template <class T, class U>
T fpow(T a, U b) {
    T x = 1;
    while (b > 0) {
        if (b%2 == 1) x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}

template <class T, class U, class V>
T fpow(T a, U b, V m) {
    T x = 1;
    while (b > 0) {
        if (b%2 == 1) x = (x*a)%m;
        a = (a*a)%m;
        b >>= 1;
    }
    return x;
}
