#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n,k;
    cin >> n >> k;
    vt<int> a(n);
    for (auto& v : a) cin >> v;
    int ans = 0;
    int target = a[k-1];
    for (int i = 0; i < n; ++i) {
        if (a[i] && a[i] >= target) {
            ans += 1;
        } else {
            break;
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