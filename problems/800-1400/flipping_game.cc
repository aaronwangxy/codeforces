#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<int> a(n);
    for (auto& v : a) cin >> v;
    int ans = 0;
    int msf = 0;
    int currsum = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            currsum += 1;
            msf = max(msf, currsum);
        } else {
            ans += 1;
            currsum = max(0, currsum-1);
        }
    }
    if (msf == 0) ans -= 1;
    cout << ans + msf << "\n";
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