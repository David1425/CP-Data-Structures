class prime_sieve {
    public:
    prime_sieve() {}
    prime_sieve(int n) { init(n); }
    
    vector<int> lowest_prime_factor;
    vector<bool> is_prime;
    vector<int> primes;
    void init(int n) {
        lowest_prime_factor.resize(n+5);
        is_prime.assign(n+5, 1);
        is_prime[1] = 0;
        for (int i = 1; i <= n; i++) lowest_prime_factor[i] = i;
        for (long long i = 2; i*i <= n; i++) {
            if (is_prime[i]) {
                for (long long j = i*i; j <= n; j += i) {
                    if (is_prime[j]) {
                        is_prime[j] = 0;
                        lowest_prime_factor[j] = i;
                    }
                }
                primes.pb(i);
            }
        }
    }
    
    int lps(int x) { return lowest_prime_factor[x]; }
    bool check(int x) { return is_prime[x]; }
    int size() { return primes.size(); }
    
    vector<int> factor(int x) {
        vector<int> fac;
        while (x > 1) {
            fac.push_back(lps(x));
            x /= lps(x);
        }
        return fac;
    }
    
    set<int> unique_factor(int x) {
        set<int> fac;
        while (x > 1) {
            fac.insert(lps(x));
            x /= lps(x);
        }
        return fac;
    }
} ps(MM);
