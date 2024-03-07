#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<ll> a(n);
    for (auto& v:a) cin >> v;
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += abs(i+1-a[i]);
    }
    cout << ans << "\n";
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