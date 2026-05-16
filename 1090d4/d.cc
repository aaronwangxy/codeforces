#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

/*
idea: for each consecutive a, b gcd is a (can multiply by 2)
when overflow, introduce a different prime
*/
void solve() {
    int n;
    cin >> n;

    int sieve[100001] = {0};
    for (int i = 2; i <= 100000; ++i) {
        if (sieve[i]) continue;
        for (int j = 2*i; j <= 100000; j += i) {
            sieve[j] = i;
        }
    }
    vt<int> primes;
    for (int i = 2; i <= 100000; ++i) {
        if (sieve[i] == 0) {
            primes.push_back(i);
        }
    }

    int prime_ptr = 0;
    bool reset = false;
    ll curr = 1;
    for (int i = 0; i < n; ++i) {
        cout << curr << " ";
        if (reset) {
            curr = primes[prime_ptr] * primes[prime_ptr];
            reset = false;
        } else if (curr * 2 > 10000000000) {
            prime_ptr += 1;
            curr *= primes[prime_ptr];
            reset = true;
        } else {
            curr *= 2;
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}