#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n,m;
    cin >> n >> m;
    vt<int> f(m);
    for (auto& v : f) cin >> v;
    sort(f.begin(), f.end());
    int ans = INT_MAX;
    int l = 0;
    for (int r = n-1; r < m; ++r) {
        ans = min(ans, f[r] - f[l]);
        l++;
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