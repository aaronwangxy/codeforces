#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

vt<pair<ll, int>> pfs(ll n) {
    // template for generating prime factors
    vt<pair<ll, int>> prime_factorization;
    for (ll p = 2; p*p <= n; p += (p == 2 ? 1 : 2)) {
        if (n % p == 0) {
            int cnt = 0;
            while (n % p == 0) {
                n /= p;
                cnt++;
            }
            prime_factorization.push_back({p, cnt});
        }
    }
    if (n > 1) {
        prime_factorization.push_back({n, 1});
    }
    return prime_factorization;
}

/*
Consider all positive divisors (except 1) of n
    - prime
    - non-prime
in each layer, all numbers can be ordered into a chain so that any two neighboring numbers in this chain have GCD∗
 greater than 1
    - all prime numbers must occupy their own layer

n = p1^e1 * p2^e2 * p3^e3 ...
values in the next layer can only increase exponent by 1
    - increasing by 2 => increase by 1 is a divisor thus must exist on preceeding layer
    - increasing 2 different exponents same logic

block 1: p1, p2, p3
block 2: p1^2, p2^2, p3^2, p1p2, p2p3, p1p3
q: can you always form a chain?
    - block 1: using 1 prime
        p1 -> p2 -> p3
    - block 2: using 2 primes
        for each element in block 1, see which prime we can multiply it by

number of prime factors + chain length - 1?
*/
void solve() {
    int n;
    cin >> n;

    vt<pair<ll, int>> prime_factorization = pfs(n);
    int total_exp = 0;
    for (auto pe : prime_factorization) {
        total_exp += pe.second;
    }
    cout << prime_factorization.size() + total_exp - 1 << "\n";
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