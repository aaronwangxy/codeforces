#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n,h;
    cin >> n >> h;
    vt<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    for (auto& v : a) {
        if (v > h) ans += 2;
        else ans += 1;
    }
    cout << ans << endl;
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