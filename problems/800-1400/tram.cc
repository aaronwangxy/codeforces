#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<int> a(n),b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    int ans = 0;
    int curr = 0;
    for (int i = 0; i < n; ++i) {
        curr += b[i] - a[i];
        ans = max(ans, curr);
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