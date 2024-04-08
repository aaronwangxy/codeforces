#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<string> a(n);
    for (auto& v : a) cin >> v;

    int ans = 1;
    string prev = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] != prev) {
            ans++;
            prev = a[i];
        }
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