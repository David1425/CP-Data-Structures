// Stress Test Generator

#include <bits/stdc++.h>

using namespace std;

mt19937_64 rng(uint64_t(new char)+chrono::steady_clock::now().time_since_epoch().count());

long long rand(long long l, long long r) {
    return l + rng()%(r-l+1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n = rand(1, 1000);
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        cout << rand(0, 1000000000) << " ";
    }
    cout << "\n";
}
