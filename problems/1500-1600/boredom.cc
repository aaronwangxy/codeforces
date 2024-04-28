#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<int> a(n);
    for (auto& v:a) cin >> v;

    map<int,ll> m;
    for (auto v:a) m[v]++;

    vt<ll> f(n+1);
    f[0] = 0; f[1] = m[1];
    for (ll i = 2; i <= n; ++i) {
        f[i] = max(f[i-1], f[i-2] + m[i]*i);
    }
    cout << f[n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}