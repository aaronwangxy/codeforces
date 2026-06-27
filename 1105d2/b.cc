#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 998244353;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

unsigned ll powmod(unsigned ll a, unsigned ll b, unsigned ll p){
    /* from https://codeforces.com/blog/entry/78873 */
    a %= p;
    if (a == 0) return 0;
    unsigned ll product = 1;
    while(b > 0){
        if (b&1){    // you can also use b % 2 == 1
            product *= a;
            product %= p;
            --b;
        }
        a *= a;
        a %= p;
        b /= 2;    // you can also use b >> 1
    }
    return product;
}

/*
1 element: must be 0 (1 option)
2 element: 0 0 or 1 1 (2 options)
3 element: 0 0  or 1 1 (reduces down to 1 element case)
4 element: 0 0 or 1 1 (reduces down to 2 element case)
n element: 2 * (n-2) options

n odd: 2 ^ (n/2)

q1: how many ways to make a clean submatrix?
0 pairs 1: n C 0
1 pairs 1: n C 2
2 pairs 1: n C 4
2^(n-1)

q2: how many ways to make a clean matrix?
start top left, shift right, have r squares to fill
- 2^(r-1) free slots, last one converts to 1 or 0 as desired
    - m - c times
- 2^(c-1) free slots, last one converts to 1 or 0 as desired
    - n - r times
rest uniquely encoded

2^(r*c-1) * (2^(r-1))^(m-c) * (2^(c-1))^(n-r)

2^(r*c-1 + (r-1)(m-c) + (c-1)(n-r))
*/
void solve() {
    unsigned ll n, m, r, c;
    cin >> n >> m >> r >> c;

    unsigned ll exp = r*c-1 + (r-1)*(m-c) + (c-1)*(n-r);
    cout << powmod(2, exp, MOD) << "\n";
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