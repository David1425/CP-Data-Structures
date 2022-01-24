class prime_sieve {
    public:
    prime_sieve() {}
    prime_sieve(int n) { init(n); }
    
    vector<int> LPF;
    vector<bool> is_prime;
    vector<int> primes;
    void init(int n) {
        LPF.resize(n+5);
        is_prime.assign(n+5, 1);
        is_prime[0] = 0;
        is_prime[1] = 0;
        for (long long i = 2; i <= n; i++) {
            if (is_prime[i]) {
                primes.push_back(i);
                LPF[i] = i;
            }
            
            for (long long j = 0; j < int(primes.size()) && primes[j] <= LPF[i] && i*primes[j] <= n; j++) {
                is_prime[i*primes[j]] = 0;
                LPF[i*primes[j]] = primes[j];
            }
        }
    }
    
    int lpf(int x) { return LPF[x]; }
    bool check(int x) { return is_prime[x]; }
    size_t size() { return primes.size(); }
    int operator () (int i) { return primes[i]; }
    
    vector<int> factor(int x) {
        vector<int> fac;
        while (x > 1) {
            fac.push_back(lpf(x));
            x /= lpf(x);
        }
        return fac;
    }
    
    set<int> unique_factor(int x) {
        set<int> fac;
        while (x > 1) {
            fac.insert(lpf(x));
            x /= lpf(x);
        }
        return fac;
    }
};
