void exgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    ll x1 = x, y1 = y;
    exgcd(b, a%b, x1, y1);
    y = x1 - (a/b)*y1;
    x = y1;
}

ll modInv(ll a, ll m) {
    ll x, y;
    if (a < m) exgcd(a, m, x, y);
    else exgcd(m, a, x, y);
    return (x%m+m)%m;
}
