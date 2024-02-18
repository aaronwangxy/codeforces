#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll m,k,p,q;
    cin >> m >> k >> p >> q;

    if (q*k > m) {
        m = m % k;
    } else {
        m -= q*k;
    }

    ll coins = 0;
    if (p < m) {
        ll r = m%k;

        if (p >= r) {
            m -= r;
            p -= r;
        } else {
            coins += r-p;
            p = 0;
            m -= r;
        }

        m = m - p/k * k;

        coins += m/k;
    }

    cout << coins << endl;
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