#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

/*
maybe: compute combinations that satisfy each possible gcd
gcd: common prime factors
lcm: gcd * unique prime factors

gcd(lcm(a, b), lcm(b, c)) = gcd(a, c)
gcd(|ab|/gcd(a,b), |bc|/gcd(b,c)) = gcd(a,c)

n

a = n * (some other prime factors)
c = n * (some other, different prime factors)
lcm(a, b) = n * (some prime factors)
    - what does this imply about b? 
        - if b is not a divisor of a: the lcm includes its unique prime factors
        - if b is a divisor of a: the lcm is just a
lcm(b, c) = n * (some different prime factors)
    - if b is a divisor of c: the lcm is just c
    - if b is not a divisor of c: the lcm includes its unique prime factors

b must be a number that divides both a and c
    - a: p1, p2
    - c: p1, p3
    - b: p2
    - lcm(a, b) = a
    - lcm(b, c) = p1, p2, p3
    - gcd of those = a
    - goal gcd: p1
*/
void solve() {
    int n;
    cin >> n;

    vt<vt<int>> divisors(n+1);
    for (int d = 1; d <= n; ++d) {
        for (int multiple = d; multiple <= n; multiple += d) {
            divisors[multiple].push_back(d);
        }
    }

    ll ans = 0;
    for (int a = 1; a <= n; ++a) {
        // For every a, how many b, c can we have?
        // number of b is number of divisors of a
        // number of c for each b is directly computable (just need some multiple)
        for (auto b: divisors[a]) {
            ans += n / b;
        }
    }
    cout << ans << "\n";
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