#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    vt<int> b(n);
    for (auto& v:b) cin >> v;

    vt<int> c(m);
    for (auto& v:c) cin >> v;

    int ans = 0;
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());

    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < m; ++j) {
            if (b[i]+c[j] <=k) ans += 1;
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